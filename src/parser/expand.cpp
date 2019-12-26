#include <string>
#include <iostream>

#include "parser.hpp"
#include "expansion/expansion.hpp"

using namespace std;

string find_expandable(string str)
{
    (void) str; //FIXME: (void)
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
     *
     * $$ are simple expanded in this function's caller, handle_map(), since
     * they are pretty basic and without condition.
     */

    return "";
}

static void handle_map(unordered_map<string, string> *map)
{
    for (auto& [key, value] : *map) {
        (*map)[key] = Expansion::expand_all(value, "$$", "$");
        cout << key << "=" << value << endl;
    }
}

void Parser::expand_vars()
{
    handle_map(p_vars);
    handle_map(p_rules);
}
