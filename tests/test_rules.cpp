#include <criterion/criterion.h>
#include <rules/rule.hpp>

Test(rule, line_valid)
{
    Rule::RuleType valid = Rule::from_line("name: deps");

    cr_assert_eq(valid.get_name(), "name");
    cr_assert_eq(valid.get_deps(), " deps");
}
