#include <iostream>
#include <stdexcept>

#include "options.hpp"

using namespace std;

variables_map *Options::g_options = NULL;

void Options::fill(int argc, char **argv)
{
    g_options = new variables_map;

    options_description cake_desc{"Cake options"};

    cake_desc.add_options()
        ("help,h", "All cake options")
        ("file,f", value<string>(), "Cakefile to use")
        ("pretty,p", "Pretty prints the different rules and variables of the Cakefile")
        ("recipes,r", value<vector<string>>()->multitoken()->zero_tokens()->composing(),
         "Recipes for cake to execute")
        ;

    positional_options_description pos_cake_desc;
    pos_cake_desc.add("recipes", -1);

    command_line_parser cake_p{argc, argv};
    cake_p.options(cake_desc).positional(pos_cake_desc).allow_unregistered();
    parsed_options cake_parsed = cake_p.run();

    store(cake_parsed, *g_options);
    notify(*g_options);

    if (g_options->count("help"))
        cout << cake_desc << endl;
}

vector<string> Options::get_recipes(void)
{
    if (!g_options)
        throw logic_error("no arguments were parsed");

    return (*g_options)["recipes"].as<vector<string>>();
}

string Options::get_file(void)
{
    if (!g_options)
        throw logic_error("no arguments were parsed");

    if (!g_options->count("file"))
        return "";

    return (*g_options)["file"].as<string>();
}
