#include "rule.hpp"

using namespace std;

Rule::Rule() : r_name(""), r_deps("")
{
}

Rule::Rule(string r_name, string r_deps)
    : r_name(r_name), r_deps(r_deps)
{
}

Rule::~Rule()
{
}

string Rule::get_name()
{
    return r_name;
}

string Rule::get_deps()
{
    return r_deps;
}

void Rule::set_name(string new_name)
{
    r_name = new_name;
}

void Rule::set_deps(string new_deps)
{
    r_deps = new_deps;
}
