// [Kurs C++] Zadanie 10
//
// Interaktywny kalkulator ONP
// Zaimplementowane funkcje: +, -, *, \, mod, min, max, log, ln, pow, abs, floor, ceil, sin, cos, atan, exp
// oraz stałe: e, pi
// Autor: Tomasz Musiała

#include <iostream>
#include "expression.hpp"
#include <string>
#include <cmath>


Number::Number(const double v)
{
     value = v;
}

double Number::eval()
{
    return value;
}

std::string Number::describe()
{
    return std::to_string(value);
}

std::vector< std::pair<std::string, double> > Variable::varSet;

Variable::Variable(std::string n)
{
    name = n;
    int exist = 0;

    for(unsigned int i = 0; i < varSet.size(); i++)
    {


        if(varSet[i].first == n)
        {
            exist = 1;
        }
    }
    if(exist == 0) varSet.push_back(std::make_pair(n, 0));
    index = varSet.size() - 1;
}

Variable::~Variable()
{
    for(unsigned int i = 0; i < varSet.size(); i++)
    {


        if(varSet[i].first == name)
            varSet.erase(varSet.begin() + i);

    }
    name = "";

}


double Variable::eval()
{
    for(unsigned int i = 0; i < varSet.size(); i++)
    {
        if(varSet[i].first == name)
            return varSet[i].second;
    }
    return 0;
}

std::string Variable::describe()
{
    return name;
}

void Variable::setValue(std::string n, double val)
{
    int len = varSet.size();
    for(int i = 0; i < len; i++)
    {
        if(varSet[i].first == n)
        {
            varSet[i].second = val;
            return;
        }
    }

    throw std::string("Variable " + n + " doesn't exist!!!");
}

double Op0Arg::eval()
{
    return value;
}

std::string Op0Arg::describe()
{
    return name;
}

Pi::Pi()
{
    value = M_PI;
    name = "pi";
}

Eu::Eu()
{
    value = M_E;
    name = "e";
}

double Op1Arg::eval()
{
    return op(arg1->eval());
}

std::string Op1Arg::describe()
{
    return name + "(" + arg1->describe() + ")";
}

Abs::Abs(Expression *e)
{
    name = "abs";
    op = &std::abs;
    arg1 = e;
}

Cos::Cos(Expression *e)
{
    name = "cos";
    op = &std::cos;
    arg1 = e;
}

Sin::Sin(Expression *e)
{
    name = "sin";
    op = &std::sin;
    arg1 = e;
}

Floor::Floor(Expression *e)
{
    name = "floor";
    op = &std::floor;
    arg1 = e;
}

Ceil::Ceil(Expression *e)
{
    name = "ceil";
    op = &std::ceil;
    arg1 = e;
}
Ln::Ln(Expression *e)
{
    name = "ln";
    op = &std::log;
    arg1 = e;
}
Atan::Atan(Expression *e)
{
    name = "atan";
    op = &std::atan;
    arg1 = e;
}
Exp::Exp(Expression *e)
{
    name = "exp";
    op = &std::exp;
    arg1 = e;
}
Minus::Minus(Expression *e)
{

    name = "-";
    op = &minus;
    arg1 = e;
}

double Minus::minus(double a)
{
    return -a;
}

double Op2Arg::eval()
{
    return op(arg1->eval(), arg2->eval());
}

std::string Op2Arg::describe()
{
    return "(" + arg1->describe() + " " + name + " " + arg2->describe() + ")";
}

Add::Add(Expression *e1, Expression *e2)
{
    name = "+";
    op = &plus;
    arg1 = e1;
    arg2 = e2;
}

double Add::plus(double a, double b)
{
    return a + b;
}

Sub::Sub(Expression *e1, Expression *e2)
{
    name = "-";
    op = &sub;
    arg1 = e1;
    arg2 = e2;
}

double Sub::sub(double a, double b)
{
    return a - b;
}

Mul::Mul(Expression *e1, Expression *e2)
{
    name = "*";
    op = &mul;
    arg1 = e1;
    arg2 = e2;
}

double Mul::mul(double a, double b)
{
    return a * b;
}

Div::Div(Expression *e1, Expression *e2)
{
    name = "/";
    op = &div;
    arg1 = e1;
    arg2 = e2;
}

double Div::div(double a, double b)
{
    if(b == 0) throw std::string("Division by 0!!!");
    return a / b;
}

Minimum::Minimum(Expression *e1, Expression *e2)
{
    name = "minimum";
    op = &minimum;
    arg1 = e1;
    arg2 = e2;
}

double Minimum::minimum(double a, double b)
{
    return std::min(a,  b);
}

Maximum::Maximum(Expression *e1, Expression *e2)
{
    name = "maximum";
    op = &maximum;
    arg1 = e1;
    arg2 = e2;
}

double Maximum::maximum(double a, double b)
{
    return std::max(a,  b);
}

Log::Log(Expression *e1, Expression *e2)
{
    name = "log";
    op = &log;
    arg1 = e1;
    arg2 = e2;
}

double Log::log(double base, double x)
{
    if(base <= 0 || base != 1 || x >= 0 ) throw std::string("Wrong logarithm arguments!!!");
    return std::log(x)/std::log(base);
}

std::string Log::describe()
{
    return "(" + name + "(" + arg1->describe() +"," + arg2->describe() + "))";
}



Pow::Pow(Expression *e1, Expression *e2)
{
    name = "^";
    op = &std::pow;
    arg1 = e1;
    arg2 = e2;
}

Mod::Mod(Expression *e1, Expression *e2)
{
    name = "%";
    op = &mod;
    arg1 = e1;
    arg2 = e2;
}

double Mod::mod(double a, double b)
{
    if(b == 0) throw std::string("Division by 0!!!");
    return double(int(a) % int(b));
}
