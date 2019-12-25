#include <iostream>
#include "rules/rule.hpp"

using namespace std;

int main(void)
{
    Rule b_rule = Rule("coucou", "no_deps");

    cout << b_rule.get_name() + " " << b_rule.get_deps() << endl;

    return 0;
}
