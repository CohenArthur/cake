#include <err.h>
#include <string>
#include <iostream>

#include "parser.hpp"
#include "expansion/expansion.hpp"

#define E_FIND_POS(Start_pattern, End_pattern, Retval) \
    pos_interest = str.find(Start_pattern); \
    if (pos_interest != string::npos) { \
        *start_pos = pos_interest; \
        *end_pos = str.substr(pos_interest, str.size()).find(End_pattern); \
        \
        if (*end_pos == string::npos) \
            return E_ERROR; \
        \
        return Retval; \
    } \

using namespace std;

enum expansion_types
{
    E_NONE,
    E_ERROR,
    E_BRACKETS,
    E_PARENTHESIS,
    E_SINGLE,
};

enum expansion_types find_expandable(string str, size_t *start_pos,
                                     size_t *end_pos)
{
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

    size_t pos_interest = string::npos;

    E_FIND_POS("$(", ')', E_PARENTHESIS);
    E_FIND_POS("${", '}', E_BRACKETS);

    if ((*start_pos = str.find('$') != string::npos)) {
        if (str.at(*start_pos + 1) == '$')
            return E_SINGLE;

        *end_pos = *start_pos + 2;
        return E_SINGLE;
    }

    return E_NONE;
}

static string value_expand_all(string value, Parser *p)
{
    value = Expansion::expand_all(value, "$$", "$");

    enum expansion_types exp = E_NONE;
    size_t start_pos;
    size_t end_pos;

    do {
        enum expansion_types exp = find_expandable(value, &start_pos, &end_pos);
        string exp_key;

        switch (exp) {
        case E_SINGLE:
            exp_key = value.substr(start_pos + 1, end_pos);
            break;
        case E_PARENTHESIS:
        case E_BRACKETS:
            exp_key = value.substr(start_pos + 2, end_pos - 2);
            break;
        case E_ERROR:
            errx(2, "parsing error when expanding %s: missing ending character",
                 value.c_str());
        case E_NONE:
            break;
        }

        value = Expansion::expand_all(
            value, value.substr(start_pos, end_pos + 1), (*p->p_vars)[exp_key]);
    } while (exp != E_NONE);

    return value;
}

void Parser::expand_vars()
{
    for (const auto& [key, value] : *p_vars)
        (*p_vars)[key] = value_expand_all(value, this);

    for (const auto& [key, value] : *p_rules) {
        Rule::RuleType to_expand = (*p_rules)[key];
        value_expand_all(to_expand.r_comm, this);
        value_expand_all(to_expand.r_deps, this);

        (*p_rules)[key] = to_expand;
    }
}
