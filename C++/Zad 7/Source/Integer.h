#pragma once

#include <exception>
#include <string>
#include <iostream>

namespace calculations {

    class bad_string : public std::exception
    {
    public:
        virtual char const * what() const throw() { return "Ill-formated string passed to Integer constructor"; }
    };

    class div0 : public std::exception
    {
    public:
        virtual char const * what() const throw() { return "Division by 0"; }
    };

    class not_natural : public std::exception
    {
    public:
        virtual char const * what() const throw() { return "Given number must be natural"; }
    };

    class Integer {

    public:
        enum class sign : bool {
            plus, minus
        };

    private:
        sign m_sign;
        int m_length;
        bool *m_bits;

    public:
        Integer() noexcept;

        Integer(int n) noexcept;
        Integer &operator=(int n) noexcept;

        Integer(const char* s) throw(bad_string);
        Integer &operator=(const char* s) throw(bad_string);

        Integer(const Integer &x) noexcept;
        Integer &operator=(const Integer &x) noexcept;

        Integer(Integer &&x) noexcept;
        Integer &operator=(Integer &&x) noexcept;

        virtual ~Integer() noexcept;

        friend bool operator==(const Integer &x, const Integer &y) noexcept;
        friend bool operator!=(const Integer &x, const Integer &y) noexcept;
        friend bool operator>(const Integer &x, const Integer &y) noexcept;
        friend bool operator<(const Integer &x, const Integer &y) noexcept;
        friend  bool operator>=(const Integer &x, const Integer &y) noexcept;
        friend bool operator<=(const Integer &x, const Integer &y) noexcept;

        friend Integer operator+(const Integer &x, const Integer &y) noexcept;
        Integer &operator+=(const Integer &y) noexcept;

        friend Integer operator-(const Integer &x, const Integer &y) noexcept;
        Integer &operator-=(const Integer &y) noexcept;

        Integer &operator++() noexcept;
        Integer operator++(int) noexcept;
        Integer &operator--() noexcept;
        Integer operator--(int) noexcept;

        friend Integer operator*(const Integer &x, const Integer &y) noexcept;
        Integer &operator*=(const Integer &y) noexcept;

        friend Integer operator/(const Integer &x, const Integer &y) throw(div0);
        Integer &operator/=(const Integer &y) throw(div0);

        friend Integer operator%(const Integer &x, const Integer &y) throw(div0);
        Integer &operator%=(const Integer &y) throw(div0);

        static Integer factorial(int n) throw(not_natural);

        inline char get_sign() const noexcept {
            return (m_sign == sign::plus ? '+' : '-');
        }

        void info() const noexcept;

        static int binary_length(unsigned int n) noexcept;

    private:

        bool test_for_bad_string(const std::string& s) noexcept;

        inline bool at(int pos) const throw(not_natural) {
            if (pos < 0) throw not_natural();
            return (pos < m_length ? m_bits[pos] : false);
        }

        inline bool front() const noexcept {
            return m_bits[m_length - 1];
        }

        Integer &trim() noexcept;
        Integer resize(int resized_length) const noexcept;
        Integer slice(int start, int end) const noexcept;
        Integer &switch_sign() noexcept;

        void make_bits(int n) noexcept;
        void make_bits(std::string s) noexcept;

        static bool equal(const Integer &x, const Integer &y) noexcept;
        // x > y
        static bool greater(const Integer &x, const Integer &y) noexcept;
        // x < y
        static bool less(const Integer &x, const Integer &y) noexcept;

        static Integer add(const Integer &x, const Integer &y) noexcept;
        static Integer sub(const Integer &x, const Integer &y) noexcept;
        static Integer mul(const Integer &x, const Integer &y) noexcept;
        static Integer div(const Integer &x, const Integer &y) noexcept;

        friend std::ostream &operator<<(std::ostream &out, const Integer &x);
        friend std::istream &operator>>(std::istream &in, Integer &x);
    };

}