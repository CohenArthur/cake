#include <iostream>

#include "options.hpp"

variables_map *Options::g_options = NULL;

void Options::fill(int argc, char **argv)
{
    g_options = new variables_map;

    options_description cake_desc{"Cake options:"};

    cake_desc.add_options()
        ("help,h", "All cake options")
        ("file,f", value<std::string>(), "Cakefile to use")
        ("pretty,p", "Pretty prints the different rules and variables of the Cakefile");

    store(parse_command_line(argc, argv, cake_desc), *g_options);
    notify(*g_options);

    if (g_options->count("help"))
        std::cout << cake_desc << std::endl;
    else if (g_options->count("file"))
        std::cout << (*g_options)["file"].as<std::string>() << std::endl;
    else if (g_options->count("pretty"))
        std::cout << "pretty" << std::endl;
}
