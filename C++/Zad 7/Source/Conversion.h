#pragma once

#include <string>

/*
    Converting strings with a decimal number to a binary number or vice versa.
 */
namespace convert
{
    // e.g. "89" -> "1011001"
    std::string decimal_to_binary(std::string decimal);

    // e.g. "1011001" -> "89"
    std::string binary_to_decimal(const std::string& binary);
}
