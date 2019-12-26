#include <criterion/criterion.h>

#include "parser/parser.hpp"

using namespace std;

Test(parser, oneline)
{
    Parser new_p = Parser();
    new_p.fill("VAR=VALUE");

    cr_assert_eq(new_p.p_vars["VAR"], "VALUE");
}

Test(parser, multivar)
{
    Parser new_p = Parser();
    new_p.fill("VAR0=VALUE0");
    new_p.fill("VAR1=VALUE1");
    new_p.fill("VAR2=VALUE2");

    cr_assert_eq(new_p.p_vars["VAR0"], "VALUE0");
    cr_assert_eq(new_p.p_vars["VAR1"], "VALUE1");
    cr_assert_eq(new_p.p_vars["VAR2"], "VALUE2");
}

Test(parser, multidef)
{
    Parser new_p = Parser();
    new_p.fill("VAR0=VALUE1");
    new_p.fill("VAR0=VALUE2");
    new_p.fill("VAR0=VALUE0");

    cr_assert_eq(new_p.p_vars["VAR0"], "VALUE0");
}

Test(parser, multirules)
{
    Parser new_p = Parser();
    new_p.fill("rule0:value0");
    new_p.fill("rule1:value1");
    new_p.fill("rule2:value2");

    cr_assert_eq(new_p.p_rules["rule0"], "value0");
    cr_assert_eq(new_p.p_rules["rule1"], "value1");
    cr_assert_eq(new_p.p_rules["rule2"], "value2");
}
