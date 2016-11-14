#include "Integer.h"
#include "Conversion.h"
#include <cctype>
#include <cstdlib>
#include <utility>
#include <algorithm>

namespace calculations {

    Integer::Integer() noexcept :
            m_sign(sign::plus),
            m_length(1),
            m_bits(new bool[1]())
    { }

    Integer::Integer(int n) noexcept {
        make_bits(n);
    }

    Integer &Integer::operator=(int n) noexcept {
        make_bits(n);
        return *this;
    }

    Integer::Integer(const char* s) throw(bad_string) {
        if (test_for_bad_string(s)) {
            throw bad_string();
        }
        make_bits(s);
    }

    Integer &Integer::operator=(const char* s) throw(bad_string) {
        if (test_for_bad_string(s)) {
            throw bad_string();
        }
        make_bits(s);
        return *this;
    }

    Integer::Integer(const Integer &x) noexcept {
        m_sign = x.m_sign;
        m_length = x.m_length;
        m_bits = new bool[m_length];
        std::copy_n(x.m_bits, m_length, m_bits);
    }

    Integer &Integer::operator=(const Integer &x) noexcept {
        m_sign = x.m_sign;
        m_length = x.m_length;
        m_bits = new bool[m_length];
        std::copy_n(x.m_bits, m_length, m_bits);
        return *this;
    }

    Integer::Integer(Integer &&x) noexcept :
            m_sign(std::move(x.m_sign)),
            m_length(std::move(x.m_length)),
            m_bits(std::move(x.m_bits)) {
        x.m_bits = nullptr;
    }

    Integer &Integer::operator=(Integer &&x) noexcept {
        m_sign = std::move(x.m_sign);
        m_length = std::move(x.m_length);
        m_bits = std::move(x.m_bits);
        x.m_bits = nullptr;
        return *this;
    }

    Integer::~Integer() noexcept {
        delete[] m_bits;
    }

    bool operator==(const Integer &x, const Integer &y) noexcept {
        if (x.m_sign != y.m_sign) {
            return false;
        }
        return Integer::equal(x, y);
    }

    bool operator!=(const Integer &x, const Integer &y) noexcept {
        return !(x == y);
    }

    bool operator>(const Integer &x, const Integer &y) noexcept {
        if (x.m_sign == Integer::sign::plus) {
            if (y.m_sign == Integer::sign::plus) {
                return Integer::greater(x, y);
            }
            else // y.m_sign == sign::minus
            {
                return true;
            }
        }
        else // x.m_sign == sign::minus
        {
            if (y.m_sign == Integer::sign::plus) {
                return false;
            }
            else // y.m_sign == sign::minus
            {
                return Integer::less(x, y);
            }
        }
    }

    bool operator<(const Integer &x, const Integer &y) noexcept {
        return y > x;
    }

    bool operator>=(const Integer &x, const Integer &y) noexcept {
        return !(x < y);
    }

    bool operator<=(const Integer &x, const Integer &y) noexcept {
        return !(x > y);
    }

    Integer operator+(const Integer &x, const Integer &y) noexcept {
        Integer result;
        if (x.m_sign == Integer::sign::plus) {
            if (y.m_sign == Integer::sign::plus) {
                result = Integer::add(x, y);
                result.m_sign = Integer::sign::plus;
            }
            else // y.m_sign == sign::minus
            {
                if (Integer::greater(x, y)) {
                    result = Integer::sub(x, y);
                    result.m_sign = Integer::sign::plus;
                }
                else {
                    result = Integer::sub(y, x);
                    result.m_sign = Integer::sign::minus;
                }
            }
        }
        else // x.m_sign == sign::minus
        {
            if (y.m_sign == Integer::sign::plus) {
                if (Integer::greater(x, y)) {
                    result = Integer::sub(x, y);
                    result.m_sign = Integer::sign::minus;
                }
                else {
                    result = Integer::sub(y, x);
                    result.m_sign = Integer::sign::plus;
                }
            }
            else // y.m_sign == sign::minus
            {
                result = Integer::add(x, y);
                result.m_sign = Integer::sign::minus;
            }
        }

        if (Integer::equal(result, 0)) {
            result.m_sign = Integer::sign::plus;
        }

        return result;
    }

    Integer &Integer::operator+=(const Integer &y) noexcept {
        *this = *this + y;
        return *this;
    }

    Integer operator-(const Integer &x, const Integer &y) noexcept {
        Integer y2 = y;
        y2.switch_sign();
        return x + y2;
    }

    Integer &Integer::operator-=(const Integer &y) noexcept {
        *this = *this - y;
        return *this;
    }

    Integer &Integer::operator++() noexcept {
        *this += 1;
        return *this;
    }

    Integer Integer::operator++(int) noexcept {
        Integer this_copy = *this;
        *this += 1;
        return this_copy;
    }

    Integer &Integer::operator--() noexcept {
        *this -= 1;
        return *this;
    }

    Integer Integer::operator--(int) noexcept {
        Integer this_copy = *this;
        *this -= 1;
        return this_copy;
    }

    Integer operator*(const Integer &x, const Integer &y) noexcept {
        Integer result = Integer::mul(x, y);
        if (result == 0) {
            result.m_sign = Integer::sign::plus;
            return result;
        }

        result.m_sign = (x.m_sign == y.m_sign) ? Integer::sign::plus : Integer::sign::minus;
        return result;
    }

    Integer &Integer::operator*=(const Integer &y) noexcept {
        *this = *this * y;
        return *this;
    }

    Integer operator/(const Integer &x, const Integer &y) throw(div0) {
        if (y == 0) {
            throw div0();
        }

        if (Integer::less(x, y)) {
            return 0;
        }

        Integer result = Integer::div(x, y);

        result.m_sign = (x.m_sign == y.m_sign) ? Integer::sign::plus : Integer::sign::minus;
        return result;
    }

    Integer &Integer::operator/=(const Integer &y) throw(div0) {
        *this = *this / y;
        return *this;
    }

    Integer operator%(const Integer &x, const Integer &y) throw(div0) {
        return x - ((x / y) * y);
    }

    Integer &Integer::operator%=(const Integer &y) throw(div0) {
        *this = *this % y;
        return *this;
    }

    Integer Integer::factorial(int n) throw(not_natural) {
        if (n < 0) {
            throw not_natural();
        }

        if (n == 1 || n == 0)
            return 1;

        return factorial(n - 1) * n;
    }

    void Integer::info() const noexcept {
        char si = get_sign();
        std::cout << "[" << *this << " " << si << " " << m_length << " ";
        for (int i = m_length - 1; i >= 0; --i) {
            std::cout << m_bits[i];
        }
        std::cout << "]" << std::endl;
    }

    int Integer::binary_length(unsigned int n) noexcept {
        int len = 1;

        while (n >>= 1) {
            ++len;
        }

        return len;
    }

    bool Integer::test_for_bad_string(const std::string& s) noexcept
    {
        int start = 0;
        if (s[0] == '-')
        {
            ++start;
        }

        return !std::all_of(s.begin()+start, s.end(), isdigit);
    }

    Integer &Integer::trim() noexcept {
        bool length_changed = false;
        while (front() == false && m_length > 1) {
            --m_length;
            length_changed = true;
        }

        if (length_changed) {
            bool *smaller = new bool[m_length];
            std::copy_n(m_bits, m_length, smaller);
            delete[] m_bits;
            m_bits = smaller;
        }

        return *this;
    }

    Integer Integer::resize(int resized_length) const noexcept {
        Integer resized;
        resized.m_length = resized_length;
        resized.m_bits = new bool[resized.m_length]();
        resized.m_sign = m_sign;

        std::copy(m_bits, m_bits + std::min(m_length, resized.m_length), resized.m_bits);

        return resized;
    }

    Integer Integer::slice(int start, int end) const noexcept {
        Integer sliced;

        sliced.m_length = end - start;
        sliced.m_bits = new bool[sliced.m_length]();
        sliced.m_sign = m_sign;

        std::copy(m_bits + start, m_bits + end, sliced.m_bits);

        return sliced;
    }

    Integer &Integer::switch_sign() noexcept {
        if (m_sign == sign::plus) {
            m_sign = sign::minus;
        }
        else {
            m_sign = sign::plus;
        }
        return *this;
    }


    void Integer::make_bits(int n) noexcept {
        m_sign = n >= 0 ? sign::plus : sign::minus;

        unsigned int un = static_cast<unsigned int>(abs(n));
        m_length = binary_length(un);

        m_bits = new bool[m_length];
        for (int i = 0; i < m_length; ++i) {
            m_bits[i] = static_cast<bool>(un % 2);
            un >>= 1;
        }
    }

    void Integer::make_bits(std::string s) noexcept {
        if (s.front() == '-') {
            s.erase(s.begin());
            if (!(s.size() == 1 && s[0] == '0')) {
                m_sign = sign::minus;
            }
        }
        else {
            m_sign = sign::plus;
        }

        s = convert::decimal_to_binary(s);

        std::reverse(s.begin(), s.end());

        m_length = s.size();
        m_bits = new bool[m_length];
        for (int i = 0; i < s.size(); ++i) {
            m_bits[i] = static_cast<bool>(s[i] - '0');
        }
    }

    bool Integer::equal(const Integer &x, const Integer &y) noexcept {
        if (x.m_length != y.m_length) {
            return false;
        }
        for (int i = 0; i < x.m_length; ++i) {
            if (x.m_bits[i] != y.m_bits[i]) {
                return false;
            }
        }
        return true;
    }

    bool Integer::greater(const Integer &x, const Integer &y) noexcept {
        if (x.m_length > y.m_length) {
            return true;
        }
        if (x.m_length < y.m_length) {
            return false;
        }
        for (int i = x.m_length - 1; i >= 0; --i) {
            if (x.m_bits[i] > y.m_bits[i]) {
                return true;
            }
            if (x.m_bits[i] < y.m_bits[i]) {
                return false;
            }
        }
        return false;
    }

    bool Integer::less(const Integer &x, const Integer &y) noexcept {
        return (!greater(x, y) && !equal(x, y));
    }

    Integer Integer::add(const Integer &x, const Integer &y) noexcept {
        Integer sum;
        delete[] sum.m_bits;
        sum.m_length = std::max(x.m_length, y.m_length) + 1;
        sum.m_bits = new bool[sum.m_length];

        sum.m_bits[0] = false;
        sum.m_bits[sum.m_length - 1] = false;

        int over = 0;
        for (int i = 0; i < sum.m_length - 1; ++i) {
            int upper = x.at(i);
            int lower = y.at(i);

            int partial = upper + lower + over;

            sum.m_bits[i] = partial % 2;
            over = partial / 2;
        }
        sum.m_bits[sum.m_length - 1] = over;

        return sum.trim();
    }

    Integer Integer::sub(const Integer &x, const Integer &y) noexcept {
        Integer diff;
        delete[] diff.m_bits;
        diff.m_length = x.m_length;
        diff.m_bits = new bool[diff.m_length];

        bool borrow = false;

        for (int i = 0; i < diff.m_length; ++i) {
            int upper = x.at(i);
            int lower = y.at(i);

            if (borrow) {
                upper -= 1;
            }

            if (upper < lower) {
                upper += 2;
                borrow = true;
            }
            else {
                borrow = false;
            }

            diff.m_bits[i] = upper - lower;
        }

        return diff.trim();
    }

    Integer Integer::mul(const Integer &x, const Integer &y) noexcept {
        Integer product = 0;
        Integer adder = x;
        for (int i = 0; i < y.m_length; ++i) {
            if (y.m_bits[i]) {
                product = add(product, adder);
            }
            adder = add(adder, adder);
        }
        return product;
    }

    Integer Integer::div(const Integer &x, const Integer &y) noexcept {
        Integer quotient = 0;
        delete[] quotient.m_bits;
        quotient.m_length = x.m_length;
        quotient.m_bits = new bool[quotient.m_length]();

        Integer partial = x.slice(x.m_length - y.m_length, x.m_length);
        for (int i = x.m_length - y.m_length; i >= 0; --i) {
            if (!less(partial, y)) {
                partial = sub(partial, y);
                quotient.m_bits[i] = true;
            }

            if (i > 0) {
                partial = add(mul(partial, 2), x.m_bits[i - 1]);
            }
        }

        return quotient.trim();
    }


    std::ostream &operator<<(std::ostream &out, const Integer &x) {
        if (x.m_sign == Integer::sign::minus) {
            out << '-';
        }

        std::string s(x.m_bits, x.m_bits + x.m_length);
        for (char &c : s) {
            c += '0';
        }
        std::reverse(s.begin(), s.end());

        out << convert::binary_to_decimal(s);
        return out;
    }

    std::istream &operator>>(std::istream &in, Integer &x) {
        std::string s;
        in >> s;
        x = s.c_str();

        return in;
    }
}
