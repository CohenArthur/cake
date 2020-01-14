#pragma once

#include <string>

/**
 * @file rule.h
 */

namespace Rule {
    class RuleType
    {
        public:
            std::string r_name;
            std::string r_deps;
            std::string r_comm;

            RuleType();
            RuleType(std::string r_name, std::string r_deps);
            RuleType(std::string line);
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

            /**
             * @brief Sets the command of a rule
             */
            void set_command(std::string new_command);
    };
}
