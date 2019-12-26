#include <unordered_map>
#include <string>

#include "rules/rule.hpp"
#include "variables/variable.hpp"

/**
 * @file parser.hpp
 */

class Parser
{
public:
    std::unordered_map<std::string, std::string> p_rules;
    std::unordered_map<std::string, std::string> p_vars;

    Parser();
    Parser(std::ifstream file);
    Parser(std::string filename);
    ~Parser();

    void fill(std::string line);
    void add_rule(std::string line);
    void add_variable(std::string line);
};
