#include <map>
#include <string>

#include "rules/rule.hpp"
#include "variables/variable.hpp"

/**
 * @file parser.hpp
 */

class Parser
{
private:
    std::map<std::string, std::string> p_rules;
    std::map<std::string, std::string> p_vars;

public:
    Parser();
    ~Parser();

    void add_rule(Rule r_to_add);
    void add_variable(Variable v_to_add);
}
