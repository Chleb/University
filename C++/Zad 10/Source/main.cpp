// [Kurs C++] Zadanie 10
//
// Interaktywny kalkulator ONP
// Zaimplementowane funkcje: +, -, *, \, mod, min, max, log, ln, pow, abs, floor, ceil, sin, cos, atan, exp
// oraz stałe: e, pi
// Autor: Tomasz Musiała

#include "expression.hpp"
#include "token.hpp"
#include <iostream>
#include  <sstream>
const int size = 100;

//Pozwoliłem sobie na małą ingerencje w sposób rozwiązania.
//Liczenie wyrażenia ONP robię na "bieżąco" korzystając tylko ze stosu (w treści zadania była mowa również o kolejce).


int main()
{
    std::string line;

    Token *t[size];
    Variable *v[size];
    int i = 0; // liczba tokenów
    int j = 0; // liczba zmiennych
    std::string command = "", token;

    while(command != "exit")
    {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> command;
        if(command == "print")
        {
            while(iss >> token)
            {
                t[i] = new Token(token);
                i++;
             }
            std::cout << "Result: ";
            t[0]->write();
        }

        if(command == "set") //zmieniłem specyfikację tego polecenia na: set <zmienna> <wyrONP>
        {
            std::string zmienna;
            iss >> zmienna;
            while(iss >> token)
            {
                t[i] = new Token(token);
                i++;
            }
            v[j] = new Variable(zmienna);
            j++;
            Variable::setValue(zmienna, t[0]->eval());
            std::cout << zmienna <<" = ";
            t[0]->write();
        }
        if(command == "clear")//czyścimy tablicę wskaźników na zmienne
        {
            for(int jj = 0; jj < j; jj++)
                delete v[jj];
            j = 0;
            std::cout << "All variables cleared!\n";
        }
        while(i > 0)//usuwamy tokeny przed następnym wyrażeniem
        {
            delete t[i - 1];
            i--;
        }

    }

    return 0;
}
