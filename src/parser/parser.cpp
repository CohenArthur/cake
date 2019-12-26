#include <iomanip>
#include <fstream>

#include "parser.hpp"

using namespace std;

enum line_types
{
    L_VAR,
    L_RULE,
    L_COMMAND,
    L_UNKNOWN,
};

Parser::Parser() : p_rules(), p_vars()
{
}

Parser::~Parser()
{
}

void Parser::add_rule(string line)
{
    Rule::RuleType r_to_add = Rule::from_line(line);
    p_rules[r_to_add.get_name()] = r_to_add.get_deps();
}

void Parser::add_variable(string line)
{
    Variable::VariableType v_to_add = Variable::from_line(line);
    p_vars[v_to_add.get_name()] = v_to_add.get_value();
}

static enum line_types get_line_type(string line)
{
    if (line.find(':') != string::npos)
        return L_RULE;
    if (line.find('=') != string::npos)
        return L_VAR;
    if (line.find('\t') != string::npos)
        return L_COMMAND;

    return L_UNKNOWN;
}

Parser::Parser(string filename)
{
    ifstream mfile;
    string line;

    mfile.open(filename);
    Parser new_p = Parser();

    while (getline(mfile, line)) {
        switch (get_line_type(line)) {
        case L_RULE:
            new_p.add_rule(line);
            break;
        case L_VAR:
            new_p.add_rule(line);
            break;
        case L_COMMAND:
        case L_UNKNOWN:
            break;
        }
    }

    //FIXME: Add exception throwing on error case
    /*
     * if (!mfile)
     *      do_something();
     */
}
