#include <iostream>

#include "options.hpp"

variables_map *Options::g_options = NULL;

void Options::fill(int argc, char **argv)
{
    g_options = new variables_map;

    options_description cake_desc{"Cake options"};

    cake_desc.add_options()
        ("help,h", "All cake options")
        ("file,f", value<std::string>(), "Cakefile to use")
        ("pretty,p", "Pretty prints the different rules and variables of the Cakefile")
        ("recipes,r", value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(),
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
        std::cout << cake_desc << std::endl;
    else if (g_options->count("file"))
        std::cout << (*g_options)["file"].as<std::string>() << std::endl;
    else if (g_options->count("pretty"))
        std::cout << "pretty" << std::endl;
    else if (g_options->count("recipes"))
        for (auto &recipe : (*g_options)["recipes"].as<std::vector<std::string>>())
            std::cout << recipe << std::endl;
}
