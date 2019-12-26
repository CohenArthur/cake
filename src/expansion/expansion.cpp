#include "expansion.hpp"

using namespace std;

string Expansion::expand(string line, string substr, string replace)
{
    size_t substr_pos = line.find(substr);
    if (substr_pos == string::npos)
        return line;

    string original_line = line;

    line = line.substr(0, substr_pos);
    line += replace;

    line +=
        original_line.substr(substr_pos + substr.size(), original_line.size());

    return line;
}

string Expansion::expand_all(string line, string substr, string replace)
{
    string prev_line;

    while (prev_line != line) {
        prev_line = line;
        line = expand(line, substr, replace);
    }

    return line;
}
