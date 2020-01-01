#include <criterion/criterion.h>

#include "command/command.hpp"

using namespace std;

Test(skip_tabs, one)
{
    string line = "\techo a";

    line = Command::skip_tabs(line);

    cr_assert_eq(line, "echo a");
}

Test(skip_tabs, multiple)
{
    string line = "\t\t\techo b";

    line = Command::skip_tabs(line);

    cr_assert_eq(line, "echo b");
}
