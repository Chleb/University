// [Kurs C++] Zadanie 4
//
// Implementacja klasy Tab_bit wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała


#ifndef TAB_BIT_HPP_INCLUDED
#define TAB_BIT_HPP_INCLUDED
#include <iostream>


class Tab_bit
{
        typedef unsigned long long word; // komorka w tablicy
        static const int wordSize = sizeof(word)*8; // rozmiar slowa w bitach

        class Ref //klasa proxy
        {
            private:
                Tab_bit *t; //wskaźnik na obiekt
                int i;      //indeks, do którego sie odwołujemy
                bool value; //wartość elementu o indeksie i

                public:
                    Ref(Tab_bit *tb, int in): t(tb),
                                              i(in),
                                              value(tb->read(in)) {}

                    Ref& operator = (const Ref &rVal)
                    {
                        if(this == &rVal) return *this;

                        t->write(i, rVal.t->read(rVal.i));
                        return *this;
                    }

                    Ref& operator = (bool bit)
                    {
                        t->write(i, bit);
                        return *this;
                    }

                    operator bool() //przeładowany operator rzutowania (przydał mi się do cout)
                    {
                        return value;
                    }

        };

    protected:
        int length; // liczba bitów
        int words; // liczba słów
        word *tab; // tablica bitów
    public:
        explicit Tab_bit(int size); // wyzerowana tablica bitow [0...rozm]
        explicit Tab_bit(word pattern);  // tablica bitów [0...rozmiarSlowa]
                                    // zainicjalizowana wzorcem
        Tab_bit(const Tab_bit &that); // konstruktor kopiujący
        Tab_bit(Tab_bit &&that); // konstruktor przenoszący
        Tab_bit &operator = (const Tab_bit &other); // przypisanie kopiujące
        Tab_bit &operator = (Tab_bit &&other); // przypisanie przenoszące
        ~Tab_bit(); // destruktor

    private:
        bool read(int i) const; // metoda pomocnicza do odczytu bitu
        bool write(int i, bool b); // metoda pomocnicza do zapisu bitu
        void checkRange(int i) const;//sprawdzenie, czy indeks znajduje się w granicach tablicy

    public:
        friend std::istream &operator >> (std::istream &in, Tab_bit &tb); //operator strumienia >>
        friend std::ostream &operator << (std::ostream &out, const Tab_bit &tb); //operator strumienia <<

        bool operator[](int i) const; // indeksowanie dla stałych tablic bitowych
        Ref operator[](int i); // indeksowanie dla zwykłych tablic bitowych

        inline int getLength() const; // rozmiar tablicy w bitach

        // operatory bitowe: | i |=, & i &=, ^ i ^= oraz ~
        friend Tab_bit operator | (const Tab_bit &a, const Tab_bit &b);
        friend Tab_bit &operator |= (Tab_bit &a, const Tab_bit &b);
        friend Tab_bit operator & (const Tab_bit &a, const Tab_bit &b);
        friend Tab_bit &operator &= (Tab_bit &a, const Tab_bit &b);
        friend Tab_bit operator ^ (const Tab_bit &a, const Tab_bit &b);
        friend Tab_bit &operator ^= (Tab_bit &a, const Tab_bit &b);
        friend Tab_bit operator ~ (const Tab_bit &a);
};


#endif // TAB_BIT_HPP_INCLUDED
