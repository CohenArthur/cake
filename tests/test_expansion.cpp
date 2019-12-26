#include <criterion/criterion.h>

#include "expansion/expansion.hpp"

using namespace std;

Test(expansion, simple)
{
    string line = "Here was Johnny !";

    line = Expansion::expand(line, "was", "is");

    cr_assert_eq(line, "Here is Johnny !");
}

Test(expansion, not_in)
{
    string line = "Here was Johnny !";

    line = Expansion::expand(line, "were", "is");

    cr_assert_eq(line, "Here was Johnny !");
}

Test(expansion_all, all_valid)
{
    string line = "ha ha ha";

    line = Expansion::expand_all(line, "ha", "ho");

    cr_assert_eq(line, "ho ho ho");
}
