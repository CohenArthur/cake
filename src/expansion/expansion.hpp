#pragma once

/**
 * @file expansion.hpp
 */

#include <string>

namespace Expansion
{
    /**
     * Replaces a given substring by another one
     */
    std::string expand(std::string line, std::string substr,
                       std::string replace);

    /**
     * Replaces all the given substrings in a string
     */
    std::string expand_all(std::string line, std::string substr,
                           std::string replace);
}
