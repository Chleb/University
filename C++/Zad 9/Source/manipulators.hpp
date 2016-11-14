// [Kurs C++] Zadanie 9
//
// Manipulatory, klasa opakowująca tablicę
// oraz krótki program testowy.
//
// Autor: Tomasz Musiała
#ifndef MANIPULATORS_HPP_INCLUDED
#define MANIPULATORS_HPP_INCLUDED
#include <iostream>

std::istream & clearline(std::istream & input);
std::ostream & comma(std::ostream & output);


class Ignore //manipulator ignorujący
{
    int amount;
    friend std::istream &operator >>(std::istream &input, const Ignore &ign);

    public:
        Ignore(int amt): amount(amt) {}
};

template<class Type>
class Array //manipulator wypisujący tablicę
{
        int size;
        Type *tab;
    public:

        friend std::ostream &operator << (std::ostream &output, const Array &arr)
        {
            int i = 0;
            if(arr.size < 0) throw std::string("Cant display less then zero elements!!!");
            output << "(";
            for(i = 0; i < arr.size - 1; i++)
                output << arr.tab[i] << comma;
            output << arr.tab[i] << ")";

            return output;
        }

    public:
        Array(Type tb[], int sz): size(sz),
                                  tab(tb)
        {}

};

template<>
class Array<char> //manipulator dla char-ów
{
        int size;
        char *tab;
    public:

        friend std::ostream &operator << (std::ostream &output, const Array &arr)
        {
            int i = 0;
            if(arr.size < 0)
            {
                while(arr.tab[i] != '\0')
                {
                    output << arr.tab[i];
                    i++;
                }
            }
            else
            {
                output << "\"";
                for(i = 0; i < arr.size - 1; i++)
                    output << arr.tab[i];
                output << arr.tab[i] << "\"";
            }
            return output;
        }

    public:
        Array(char tb[], int sz): size(sz),
                                  tab(tb)
        {}

};



#endif // MANIPULATORS_HPP_INCLUDED
