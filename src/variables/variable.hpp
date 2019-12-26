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

        std::string get_name();
        std::string get_value();
    };

    VariableType from_line(std::string line);
}
