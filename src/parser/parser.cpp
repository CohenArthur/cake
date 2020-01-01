#include <iomanip>
#include <fstream>

#include "parser.hpp"
#include "comment/comment.hpp"

using namespace std;

enum line_types
{
    L_VAR,
    L_RULE,
    L_COMMAND,
    L_UNKNOWN,
};

Parser::Parser()
{
    p_vars = new unordered_map<string, string>;
    p_rules = new unordered_map<string, Rule::RuleType>;
}

Parser::~Parser()
{
    delete p_vars;
    delete p_rules;
}

void Parser::add_rule(string line)
{
    Rule::RuleType r_to_add = Rule::from_line(line);
    p_last_rule = r_to_add;

    (*p_rules)[r_to_add.get_name()] = r_to_add;
}

void Parser::add_variable(string line)
{
    Variable::VariableType v_to_add = Variable::from_line(line);
    (*p_vars)[v_to_add.get_name()] = v_to_add.get_value();
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

void Parser::fill(string line)
{
    line = Comment::skip(line);

    switch (get_line_type(line)) {
        case L_RULE:
            add_rule(line);
            break;
        case L_VAR:
            add_variable(line);
            break;
        case L_COMMAND:
            p_last_rule.set_command(line);
        case L_UNKNOWN:
            break;
    }
}

Parser::Parser(ifstream file)
{
    Parser new_p = Parser();
    string line;

    while (getline(file, line))
        new_p.fill(line);
}

Parser::Parser(string filename)
{
    ifstream mfile;

    mfile.open(filename);

    Parser new_p = Parser();
    string line;

    while (getline(mfile, line))
        new_p.fill(line);
}
