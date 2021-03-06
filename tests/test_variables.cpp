#include <criterion/criterion.h>

#include "variables/variable.hpp"

Test(variable, line_valid)
{
    Variable::VariableType valid = Variable::VariableType("name= deps");

    cr_assert_eq(valid.get_name(), "name");
    cr_assert_eq(valid.get_value(), " deps");
}
