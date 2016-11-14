// [Kurs C++] Zadanie 9
//
// Manipulatory, klasa opakowująca tablicę
// oraz krótki program testowy.
//
// Autor: Tomasz Musiała
#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include "manipulators.hpp"
#include <iostream>

template<class Type>
class Table
{
    int size; //rozmiar
    Type *tab; //wskaźnik na tablicę


    public:

        Table(int sz): size(sz) //konstruktor z rozmiarem
        {
            tab = new Type[size];
        }

        Table(Table<Type> &t): size(t.size) //konstruktor kopiujący
        {
            tab = new Type[size];
            for(int i = 0; i < size; i++)
            {
                tab[i] = t[i];
            }
        }

        Table(Table<Type> &t, int sz): size(sz) //konstruktor kopiujący uwzględniający rozmiar
        {
            tab = new Type[sz];
            for(int i = 0; i < sz; i++)
            {
                if(i < t.size) tab[i] = t[i];
            }
        }

        Table(Table<Type> &&t): size(t.size) //kontruktor przenoszący
        {
            tab = t.tab;
            t.size = 0;
            t.tab = nullptr;
        }

        Table(std::initializer_list<Type> l): size(l.size()) //konstruktor z listą
        {
            int i = 0;
            tab = new Type[size];
            for(auto iter = l.begin(); iter != l.end(); iter++, i++)
            {
                tab[i] = *iter;
            }
        }

        ~Table() //destruktor
        {
            size = 0;
            delete[] tab;
        }

        Type &operator[](int i) const //operator []
        {
            return tab[i] ;
        }

        Type &operator[](int i)
        {
            return tab[i] ;
        }

        Table &operator = (const Table &other) //operatory przypisania
        {
            if(this == &other) return *this;

            for(int i = 0; i < size && i < other.size; i++)
                tab[i] = other.tab[i];
            return *this;

        }
        Table &operator = (Table &&other)
        {
            if(this == &other) return *this;
            tab = other.tab;
            other.size = 0;
            other.tab = nullptr;
            return *this;
        }

        friend std::ostream &operator << (std::ostream &output, const Table &t)
        {
            output << Array<Type>(t.tab, t.size);
            return output;
        }

        friend std::istream &operator >> (std::istream &input, Table &t)
        {
            int chr = input.peek();
            int i = 0;

            while(chr != '(' && chr != '\"')
            {
                input.ignore();
                chr = input.peek();
            }

            input.ignore();

            if(chr == '(')//gdy mamy do czynienia z (x, y, z)
            {
                while(i < t.size && chr != ')')
                {
                    input >> t[i];
                    chr = input.peek();
                    if(chr != ')') input >> Ignore(2);
                    i++;
                }

            }
            else//gdzy mamy do czynienia z "asd"
            {
                chr = input.peek();
                while(i < t.size && chr != '\"')
                {
                    input >> t[i];
                    chr = input.peek();
                    i++;
                }
            }

            input.ignore();
            return input;
        }

};




#endif // TABLE_HPP_INCLUDED
