// [Kurs C++] Zadanie 10
//
// Interaktywny kalkulator ONP
// Zaimplementowane funkcje: +, -, *, \, mod, min, max, log, ln, pow, abs, floor, ceil, sin, cos, atan, exp
// oraz stałe: e, pi
// Autor: Tomasz Musiała
#include "token.hpp"
#include "expression.hpp"
#include <string>
#include <stack>
#include <iostream>

std::stack<Token> Token::tokenStack;

Token::Token(std::string str) //Parsowanie dzieje się w konstruktorze, który
                              //rozpoznaje typ wyrażenia, jakie ma utworzyć i wykonuje
                              //odpowiednie operacje na stosie
{
    if(isdigit(str[0]))
    {
        exp = new Number(stod(str));
        tokenStack.push(*this);
    }
    else if(str == "e")
    {
        exp = new Eu();
        tokenStack.push(*this);
    }
    else if(str == "pi")
    {
        exp = new Pi();
        tokenStack.push(*this);
    }
    else if(str == "-")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Sub(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "+")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();
        Token arg2 = tokenStack.top();
        tokenStack.pop();

        exp = new Add(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "*")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();
        Token arg2 = tokenStack.top();
        tokenStack.pop();

        exp = new Mul(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "\\")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Div(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
   else if(str == "min")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Minimum(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
   else if(str == "max")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Maximum(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "pow")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Pow(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "mod")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Mod(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "log")
    {
        Token arg2 = tokenStack.top();
        tokenStack.pop();
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Log(arg1.exp, arg2.exp);
        tokenStack.push(*this);
    }
    else if(str == "sin")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Sin(arg1.exp);
        tokenStack.push(*this);
    }
    else if(str == "cos")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Cos(arg1.exp);
        tokenStack.push(*this);
    }
    else if(str == "abs")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Abs(arg1.exp);
        tokenStack.push(*this);
    }
    else if(str == "floor")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Floor(arg1.exp);
        tokenStack.push(*this);
    }
    else if(str == "ln")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Ln(arg1.exp);
        tokenStack.push(*this);
    }
    else if(str == "atan")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Atan(arg1.exp);
        tokenStack.push(*this);
    }
    else if(str == "exp")
    {
        Token arg1 = tokenStack.top();
        tokenStack.pop();

        exp = new Exp(arg1.exp);
        tokenStack.push(*this);
    }
    else
    {
        exp = new Variable(str);
        tokenStack.push(*this);
    }

}

double Token::eval()
{
    return ((tokenStack.top()).exp)->eval();
}

void Token::write()
{
     if(tokenStack.size() != 1) std::cout << "Incorrect ONP expression!\n";
     else std::cout << (((tokenStack.top()).exp)->eval()) << "\n";
     while(!(tokenStack.empty())) tokenStack.pop(); //opróżniamy stos
}
