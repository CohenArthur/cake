#include <string.h>

#include "rule.hpp"

using namespace std;

Rule::RuleType Rule::from_line(string line)
{
    return RuleType(line, line);
}
