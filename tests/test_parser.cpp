#include <criterion/criterion.h>

#include "parser/parser.hpp"

using namespace std;

Test(parser, oneline)
{
    Parser new_p = Parser();
    new_p.fill("VAR=VALUE");

    cr_assert_eq(new_p.p_vars["VAR"], "VALUE");
}
