#include "command.hpp"

using namespace std;

string Command::skip_tabs(const string &command)
{
    auto string_begin = command.find_first_not_of('\t');

    return command.substr(string_begin, command.size());
}
