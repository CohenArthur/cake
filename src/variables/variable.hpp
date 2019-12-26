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
        ~VariableType();

        /**
         * @brief Returns the variable name
         */
        std::string get_name();

        /**
         * @brief Returns the variable value
         */
        std::string get_value();
    };


    /**
     * @brief Creates a variable from a given line
     */
    VariableType from_line(std::string line);
}
