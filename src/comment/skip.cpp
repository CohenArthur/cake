#include "comment.hpp"

std::string Comment::skip(std::string line)
{
    size_t comment_pos = line.find('#');

    return line.substr(0, comment_pos);
}
