#include <iostream>
#include "rules/rule.hpp"

using namespace std;

int main(void)
{
    Rule::RuleType b_rule = Rule::from_line("name: deps");

    cout << b_rule.get_name() + " " << b_rule.get_deps() << endl;

    return 0;
}
