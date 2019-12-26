#include <unordered_map>
#include <string>

#include "rules/rule.hpp"
#include "variables/variable.hpp"

/**
 * @file parser.hpp
 */

class Parser
{
private:
    std::unordered_map<std::string, std::string> p_rules;
    std::unordered_map<std::string, std::string> p_vars;

public:
    Parser();
    Parser(std::string filename);
    ~Parser();

    void add_rule(std::string line);
    void add_variable(std::string line);
};
