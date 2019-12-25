#include <string>

/**
 * @file rule.h
 */

namespace Rule {
    class RuleType
    {
        private:
            std::string r_name;
            std::string r_deps;

        public:
            /**
             * @brief Builds a new rule with empty strings
             */
            RuleType();

            /**
             * @brief Builds a new rule with the given strings
             */
            RuleType(std::string r_name, std::string r_deps);

            ~RuleType();

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

    /**
     * @brief Builds a rule from a given line.
     */
    RuleType from_line(std::string line);
}