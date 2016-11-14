// [Kurs C++] Zadanie 10
//
// Interaktywny kalkulator ONP
// Zaimplementowane funkcje: +, -, *, \, mod, min, max, log, ln, pow, abs, floor, ceil, sin, cos, atan, exp
// oraz stałe: e, pi
// Autor: Tomasz Musiała

#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include <string>
#include <vector>

constexpr auto M_PI = 3.14159265358979323846; //definicje stałych
constexpr auto M_E =  2.71828182845904523536;

class Expression //klasa abstrakcyjna
{
    protected:
        std::string name; //pole z nazwą używaną przy wypisywaniu wyrażenia
        double value;     //pole z wartością wyrażenia
    public:
        virtual double eval() = 0;          //metoda wartościująca
        virtual std::string describe() = 0; //metoda wypisująca

};

class Number :public Expression //klasa reprezentująca liczbę
{
    public:
        Number(const double v);

        virtual double eval();
        virtual std::string describe();
};

class Variable :public Expression //klasa reprezentująca zmienną
{
    private:
        static std::vector< std::pair<std::string, double> > varSet; //statyczny zbiór par
                                                         // <nazwa, wartość>
        int index; //indeks w varSet

    public:
        Variable(std::string n);
        virtual ~Variable(); // należy usunąć element z varSet


        static void setValue(std::string n, double val); //metoda pozwalająca przypisać wszystkim wystąpieniom
                                                         //zmiennej o nazwie n wartość val
                                                         //Jeśli nie ma zmiennej o tej nazwie rzucany jest wyjątek
        virtual double eval();
        virtual std::string describe();


};

class Op0Arg :public Expression //operator 0-arg
{
    public:
        virtual double eval();
        virtual std::string describe();


};

class Pi :public Op0Arg //stała pi
{
    public:
        Pi();
};

class Eu :public Op0Arg //stała e
{
    public:
        Eu();
};

class Op1Arg :public Op0Arg // operator 1-arg
{
    protected:
        Expression *arg1;
        double (*op)(double); // wskaźnik do funkcji odpowiadającej operatorowi
    public:
        virtual double eval();
        virtual std::string describe();

};

class Abs :public Op1Arg //wart. absolutna
{
    public:
        Abs(Expression *e);
};

class Cos :public Op1Arg // cosinus
{
    public:
        Cos(Expression *e);
};

class Sin :public Op1Arg //sinus
{
    public:
        Sin(Expression *e);
};

class Floor :public Op1Arg //sinus
{
    public:
        Floor(Expression *e);
};

class Ceil :public Op1Arg //sinus
{
    public:
        Ceil(Expression *e);
};

class Ln :public Op1Arg //sinus
{
    public:
        Ln(Expression *e);
};
class Atan :public Op1Arg //sinus
{
    public:
        Atan(Expression *e);
};
class Exp :public Op1Arg //sinus
{
    public:
        Exp(Expression *e);
};
class Minus :public Op1Arg //zmiana znaku
{
    private:
        static double minus(double a);
    public:
        Minus(Expression *e);
};

class Op2Arg :public Op1Arg //op. 2-arg.
{
    protected:
        Expression *arg2;
        double (*op)(double, double);
    public:
        virtual double eval();
        virtual std::string describe();

};

class Add :public Op2Arg
{
    private:
        static double plus(double a, double b);
    public:
        Add(Expression *e1, Expression *e2);
};

class Sub :public Op2Arg
{
    private:
        static double sub(double a, double b);
    public:
        Sub(Expression *e1, Expression *e2);
};

class Mul :public Op2Arg
{
    private:
        static double mul(double a, double b);
    public:
        Mul(Expression *e1, Expression *e2);
};

class Div :public Op2Arg
{
    private:
        static double div(double a, double b);
    public:
        Div(Expression *e1, Expression *e2);
};
class Minimum :public Op2Arg
{
    private:
        static double minimum(double a, double b);
    public:
        Minimum(Expression *e1, Expression *e2);
};

class Maximum :public Op2Arg
{
    private:
        static double maximum(double a, double b);
    public:
        Maximum(Expression *e1, Expression *e2);
};

class Log :public Op2Arg
{
   private:
        static double log(double base, double x);
    public:
        Log(Expression *e1, Expression *e2);
        virtual std::string describe();
};

class Pow :public Op2Arg
{
    public:
        Pow(Expression *e1, Expression *e2);
};

class Mod :public Op2Arg
{
   private:
        static double mod(double a, double b);
    public:
        Mod(Expression *e1, Expression *e2);

};

#endif // EXPRESSION_HPP_INCLUDED
