#ifndef TABBIT_HPP_INCLUDED
#define TABBIT_HPP_INCLUDED

#include <iostream>
using namespace std;

class ref;

class tab_bit
{
private:
    typedef unsigned long long slowo; // komorka w tablicy
    static const int rozmiarSlowa; // rozmiar slowa w bitach
    friend istream & operator >> (istream &we, tab_bit &tb);// jesli zostanie podany ciag bitow
                                                            //  dluzszy niz pojemnosc tab_bit to odcina najmniej znaczace bity
    friend ostream & operator << (ostream &wy, const tab_bit &tb);
    friend class ref; // klasa pomocnicza dla operatora indeksowania
protected:
    int dl; // liczba bitów
    slowo *tab; // tablica bitów
public:
    explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit (slowo tb); // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
    tab_bit(); // tablica o rozmiarze rozmiarSlowa
    tab_bit (const tab_bit &tb); // konstruktor kopiujący
    tab_bit (tab_bit &&tb); // konstruktor przenoszący
    tab_bit & operator = (const tab_bit &tb); // przypisanie kopiujące
    tab_bit & operator = (tab_bit &&tb); // przypisanie przenoszące
    ~tab_bit (); // destruktor
private:
    bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu
    bool pisz (int i, bool b); // metoda pomocnicza do zapisu bitu
public:
    bool operator[] (int i) const; // indeksowanie dla staªych tablic bitowych
                                   // rzuca wyjatek przy i spoza zakresu tablicy
    ref operator[] (int i); // indeksowanie dla zwyklych tablic bitowych
                            // zachoanie niezdefiniowane dla i spoza zakresu tablicy
    inline int rozmiar () const; // rozmiar tablicy w bitach
public:
    tab_bit & operator |= (const tab_bit &tb);
    tab_bit & operator &= (const tab_bit &tb);
    tab_bit & operator ^= (const tab_bit &tb);
public:
    friend tab_bit operator | (const tab_bit &tb1, const tab_bit &tb2);
    friend tab_bit operator & (const tab_bit &tb1, const tab_bit &tb2);
    friend tab_bit operator ^ (const tab_bit &tb1, const tab_bit &tb2);
    friend tab_bit operator ! (const tab_bit &tb);
};

class ref
{
private:
    friend class tab_bit;
    unsigned long long *tab;
    int nr_bitu;
    ref(tab_bit &tb);
public:
    ~ref();
    ref& operator = (bool bit);
    ref& operator = (const ref& bit);
    operator bool() const;
    bool operator ! () const;
};

int tab_bit::rozmiar () const { return dl;}

#endif // TABBIT_HPP_INCLUDED
