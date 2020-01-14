#include "variable.hpp"

using namespace std;
using namespace Variable;

VariableType::VariableType()
    : v_name(""), v_value("")
{
}

VariableType::VariableType(string v_name, string v_value)
    : v_name(v_name), v_value(v_value)
{
}

VariableType::VariableType(string line)
{
    size_t equal_pos = line.find('=');

    v_name = line.substr(0, equal_pos);
    v_value = line.substr(equal_pos + 1, line.size());
}

VariableType::~VariableType()
{
}

string VariableType::get_name()
{
    return v_name;
}

string VariableType::get_value()
{
    return v_value;
}

void VariableType::set_name(string new_name)
{
    v_name = new_name;
}

void VariableType::set_value(string new_value)
{
    v_value = new_value;
}
