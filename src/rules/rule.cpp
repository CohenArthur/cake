#include "rule.hpp"

using namespace std;

Rule::RuleType::RuleType() : r_name(""), r_deps("")
{
}

Rule::RuleType::RuleType(string r_name, string r_deps)
    : r_name(r_name), r_deps(r_deps)
{
}

Rule::RuleType::RuleType(string line)
{
    size_t colon_pos = line.find(':');

    r_name = line.substr(0, colon_pos);
    r_deps = line.substr(colon_pos + 1, line.size());
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

void Rule::RuleType::set_command(string new_command)
{
    r_comm = new_command;
}
