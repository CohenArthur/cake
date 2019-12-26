#include "variable.hpp"

using namespace std;
using namespace Variable;

VariableType::VariableType()
    : v_name(""), v_value("")
{
}

VariableType::VariableType(std::string v_name, std::string v_value)
    : v_name(v_name), v_value(v_value)
{
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
