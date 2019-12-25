#include <string>

/**
 * @file rule.h
 */

class Rule
{
private:
    std::string r_name;
    std::string r_deps;

public:
    /**
     * @brief Builds a new rule with empty strings
     */
    Rule();

    /**
     * @brief Builds a new rule with the given strings
     */
    Rule(std::string r_name, std::string r_deps);

    ~Rule();

    /**
     * @brief Returns the name of a rule
     */
    std::string get_name();

    /**
     * @brief Returns the dependencies of a rule
     */
    std::string get_deps();

    /**
     * @brief Sets the name of a rule
     */
    void set_name(std::string new_name);

    /**
     * @brief Sets the dependencies of a rule
     */
    void set_deps(std::string new_deps);
};
