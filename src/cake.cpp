#include <iostream>
#include "parser/parser.hpp"
#include "options/options.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Parser m_parser = Parser();

    m_parser.fill("VAR0= coucou");
    m_parser.fill("VAR1= $(VAR0)");
    m_parser.fill("VAR2= $$?");
    m_parser.fill("a=waouh");
    m_parser.fill("rule0: deps0");
    m_parser.fill("rule1: ${VAR1}");
    m_parser.fill("rule2: $a");

    m_parser.expand_vars();

    (void) argc;
    (void) argv;

    Options::fill(argc, argv);

    return 0;
}
