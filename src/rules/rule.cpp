#include "rule.hpp"

using namespace std;

Rule::RuleType::RuleType() : r_name(""), r_deps("")
{
}

Rule::RuleType::RuleType(string r_name, string r_deps)
    : r_name(r_name), r_deps(r_deps)
{
}

Rule::RuleType::~RuleType()
{
}

string Rule::RuleType::get_name()
{
    return r_name;
}

string Rule::RuleType::get_deps()
{
    return r_deps;
}

void Rule::RuleType::set_name(string new_name)
{
    r_name = new_name;
}

void Rule::RuleType::set_deps(string new_deps)
{
    r_deps = new_deps;
}
