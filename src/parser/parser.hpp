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
    std::unordered_map<std::string, Rule::RuleType *> *p_rules;
    std::unordered_map<std::string, std::string> *p_vars;

    Rule::RuleType p_last_rule;

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

    /**
     * @brief Expands the variables in the parser
     */
    void expand_vars();

    /**
     * @brief Returns a rule from the parser based on its name
     */
    Rule::RuleType *get_rule(std::string rulename);

    /**
     * @brief Returns a variable from the parser based on its name
     */
    std::string get_var(std::string varname);
};
