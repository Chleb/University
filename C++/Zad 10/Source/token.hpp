// [Kurs C++] Zadanie 10
//
// Interaktywny kalkulator ONP
// Zaimplementowane funkcje: +, -, *, \, mod, min, max, log, ln, pow, abs, floor, ceil, sin, cos, atan, exp
// oraz stałe: e, pi
// Autor: Tomasz Musiała

#ifndef TOKEN_HPP_INCLUDED
#define TOKEN_HPP_INCLUDED
#include "expression.hpp"
#include <stack>
#include <string>

class Token
{
    private:
        static std::stack< Token > tokenStack;

        Expression *exp;//wskaźnik na wyrażenie

    public:
        Token(std::string);
        double eval();//wylicza wartość wyrażenie w tokenie
        void write(); //wypisuje wartość wyrażenie w tokenie

};




#endif // TOKEN_HPP_INCLUDED
