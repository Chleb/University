#include "Conversion.h"
#include <iostream>
#include <vector>
#include <algorithm>

// helper functions - only for this this scope

// Like std::string::at but returns 0 if pos is out of range
char string_at(const std::string& s, int pos);

std::string add_decimals(const std::string& a, const std::string& b);

std::string decimal_x2(const std::string& a);

std::string decimal_d2(std::string& a);


char string_at(const std::string& s, int pos)
{
    return pos < s.size() ? s[pos] : static_cast<char>(0);
}

std::string add_decimals(const std::string& a, const std::string& b)
{
    std::string sum(std::max(a.size(), b.size()) + 1, 0);
    for (int i = 0 ; i < sum.size() - 1 ; ++i)
    {
        sum[i] += string_at(a, i) + string_at(b, i);
        sum[i + 1] = sum[i] / 10;
        sum[i] %= 10;
    }

    if (sum.size() > 0 && sum.back() == 0)
    {
        sum.pop_back();
    }

    return sum;
}

std::string decimal_x2(const std::string& a)
{
    return add_decimals(a, a);
}

std::string decimal_d2(std::string& a)
{
    for (int i = a.size() - 1 ; i > 0 ; --i)
    {
        a[i-1] += a[i]%2 * 10;
        a[i] /= 2;
    }
    a[0] /= 2;

    if (a.size() > 0 && a.back() == 0)
    {
        a.pop_back();
    }

    return a;
}

namespace convert
{
    std::string decimal_to_binary(std::string decimal)
    {
        for (char &c : decimal)
        {
            c -= '0';
        }

        std::reverse(decimal.begin(), decimal.end());

        // It's difficult to predict the length of the resulting binary number,
        // so we're gonna create it bit by bit.
        // We use vector for better performance - we want inexpensive push_backs
        std::vector<char> r;
        while (decimal != "\0")
        {
            r.push_back(static_cast<char>(decimal.front() % 2) + '0');
            decimal_d2(decimal);
        }

        return std::string(r.rbegin(), r.rend());
    }

    std::string binary_to_decimal(const std::string& binary)
    {
        std::string decimal(1, static_cast<char>(0));
        std::string adder(1, static_cast<char>(1));

        for (int i = binary.size() - 1 ; i >= 0 ; --i)
        {
            if (binary[i] == '1')
            {
                decimal = add_decimals(decimal, adder);
            }

            adder = decimal_x2(adder);
        }

        for (char &c : decimal)
        {
            c += '0';
        }

        return std::string(decimal.rbegin(), decimal.rend());
    }
}

