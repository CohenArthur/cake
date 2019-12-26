#include <string>
#include <iostream>

#include "parser.hpp"

using namespace std;

string find_expandable(string str)
{
    (void) str;
    /**
     * There are three ways to expand variables in Makefiles:
     *      - $V
     *      - ${VAR}
     *      - $(VAR)
     *      - $$VAR
     *
     * ${} and $() are equivalent. $$ should be expanded to $, in order to
     * let the shell expand it.
     *
     * $VAR is the same as expanding $V. Without the parentheses or brackets,
     * only a single letter is considered as the name.
     */

    return "";
}

void Parser::expand_vars()
{
    for (const auto& [key, value] : p_vars) {
        cout << key << "=" << value << endl;
    }

    for (const auto& [key, value] : p_rules) {
        cout << key << "=" << value << endl;
    }
}
