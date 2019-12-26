#include "variable.hpp"

using namespace std;

Variable::VariableType Variable::from_line(string line)
{
    size_t equal_pos = line.find('=');

    string name = line.substr(0, equal_pos);
    string value = line.substr(equal_pos + 1, line.size());

    return VariableType(name, value);
}
