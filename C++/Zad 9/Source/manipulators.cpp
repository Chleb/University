// [Kurs C++] Zadanie 9
//
// Manipulatory, klasa opakowująca tablicę
// oraz krótki program testowy.
//
// Autor: Tomasz Musiała
#include "manipulators.hpp"
#include <iostream>

std::istream & clearline(std::istream & input) //manipulator czyszczący linię
{
    int chr = 0;

    while((chr = input.peek()) != '\n') //nie sprawdzamy EOF, bo ignore robi to za nas
        input.ignore();
    input.ignore();

    return input;
}

std::ostream & comma(std::ostream & output) //manipulator wstawiający ", "
{
    output << ", ";
    return output;
}



std::istream &operator >> (std::istream &input, const Ignore &ign) //manipulator ignorujący znaki do nowej linii
{
        input.ignore(ign.amount, '\n');
        return input;
}
