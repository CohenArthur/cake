#pragma once

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

    /**
     * @brief Adds a new line, whatever the type, to the parser.
     */
    void fill(std::string line);

    /**
     * @brief Adds a new rule to the parser.
     */
    void add_rule(std::string line);

    /**
     * @brief Adds a new variable to the parser.
     */
    void add_variable(std::string line);
};
