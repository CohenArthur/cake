#include <string.h>

#include "rule.hpp"

using namespace std;

Rule::RuleType Rule::from_line(string line)
{
    size_t colon_pos = line.find(':');

    string name = line.substr(0, colon_pos);
    string deps = line.substr(colon_pos + 1, line.size());

    return RuleType(name, deps);
}
