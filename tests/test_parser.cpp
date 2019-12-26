#include <criterion/criterion.h>

#include "parser/parser.hpp"

using namespace std;

Test(parser, oneline)
{
    Parser new_p = Parser();
    new_p.fill("VAR=VALUE");

    cr_assert_eq((*new_p.p_vars)["VAR"], "VALUE");
}

Test(parser, multivar)
{
    Parser new_p = Parser();
    new_p.fill("VAR0=VALUE0");
    new_p.fill("VAR1=VALUE1");
    new_p.fill("VAR2=VALUE2");

    cr_assert_eq((*new_p.p_vars)["VAR0"], "VALUE0");
    cr_assert_eq((*new_p.p_vars)["VAR1"], "VALUE1");
    cr_assert_eq((*new_p.p_vars)["VAR2"], "VALUE2");
}

Test(parser, multidef)
{
    Parser new_p = Parser();
    new_p.fill("VAR0=VALUE1");
    new_p.fill("VAR0=VALUE2");
    new_p.fill("VAR0=VALUE0");

    cr_assert_eq((*new_p.p_vars)["VAR0"], "VALUE0");
}

Test(parser, multirules)
{
    Parser new_p = Parser();
    new_p.fill("rule0:value0");
    new_p.fill("rule1:value1");
    new_p.fill("rule2:value2");

    cr_assert_eq((*new_p.p_rules)["rule0"], "value0");
    cr_assert_eq((*new_p.p_rules)["rule1"], "value1");
    cr_assert_eq((*new_p.p_rules)["rule2"], "value2");
}

Test(parser, rule_with_comment)
{
    Parser new_p = Parser();
    new_p.fill("rule0:value0#This is a comment");
    new_p.fill("rule1:value1#Holy #There are #Multiple #comments");

    cr_assert_eq((*new_p.p_rules)["rule0"], "value0");
    cr_assert_eq((*new_p.p_rules)["rule1"], "value1");
}

Test(parser, expansion_dollardollar)
{
    Parser m_parser = Parser();

    m_parser.fill("VAR0=$$?");

    m_parser.expand_vars();

    cr_assert_eq((*m_parser.p_vars)["VAR0"], "$?");
}

/*
Test(parser, expansion_dollar_parentheses)
{
    Parser m_parser = Parser();

    m_parser.fill("VAR0= Caribou");
    m_parser.fill("VAR1= $(VAR0)");

    m_parser.expand_vars();

    cr_assert_eq(m_parser.p_vars["VAR1"], "Caribou");
}

Test(parser, expansion_dollar_parentheses_nested)
{
    Parser m_parser = Parser();

    m_parser.fill("VAR0= Caribou");
    m_parser.fill("VAR1= $(VAR0)");
    m_parser.fill("VAR2= $(VAR1)");

    m_parser.expand_vars();

    cr_assert_eq(m_parser.p_vars["VAR2"], "Caribou");
}
*/
