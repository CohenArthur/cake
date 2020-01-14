#pragma once

#include <string>

namespace Variable
{
    class VariableType
    {
    private:
        std::string v_name;
        std::string v_value;

    public:
        VariableType();
        VariableType(std::string v_name, std::string v_val);
        VariableType(std::string line);
        ~VariableType();

        /**
         * @brief Returns the variable name
         */
        std::string get_name();

        /**
         * @brief Returns the variable value
         */
        std::string get_value();

        /**
         * @brief Sets the variable name
         */
        void set_name(std::string v_value);

        /**
         * @brief Sets the variable value
         */
        void set_value(std::string v_value);
    };
}
