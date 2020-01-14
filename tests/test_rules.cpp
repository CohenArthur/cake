#include <criterion/criterion.h>

#include "rules/rule.hpp"
#include "comment/comment.hpp"

Test(rule, line_valid)
{
    Rule::RuleType valid = Rule::RuleType("name: deps");

    cr_assert_eq(valid.get_name(), "name");
    cr_assert_eq(valid.get_deps(), " deps");
}

Test(rule, line_valid_with_comment)
{
    std::string line = "name: deps#this is a comment";
    line = Comment::skip(line);

    Rule::RuleType valid = Rule::RuleType(line);

    cr_assert_eq(valid.get_name(), "name");
    cr_assert_eq(valid.get_deps(), " deps");
}
