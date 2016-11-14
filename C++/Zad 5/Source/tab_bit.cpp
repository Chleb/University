// [Kurs C++] Zadanie 4
//
// Implementacja klasy Tab_bit wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała

#include "tab_bit.hpp"
#include <algorithm>
#include <iostream>
#include <string>

Tab_bit::Tab_bit(int size): length(size)
{
    words = (length / wordSize) + 1;
    tab = new word[words];  //alokujemy wyzerowaną tablicę wordów

    for(int i = 0; i < words; i++) tab[i] = 0; // i zerujemy ją (mógłbym użyć new[](), ale nie jestem pewien
}                                              // jak to dokładnie działa)

Tab_bit::Tab_bit(word pattern): length(wordSize),
                                words(1)
{
    tab = new word[1];
    tab[0] = pattern;
}

Tab_bit::Tab_bit(const Tab_bit &that): length(that.length)
{
    words = (length / wordSize) + 1;

    tab = new word[words];
    for(int i = 0; i < words; i++) tab[i] = that.tab[i];
}

Tab_bit::Tab_bit(Tab_bit &&that): length(that.length),
                                  words(that.words)
{
    tab = that.tab;
    that.tab = nullptr;
    that.length = 0; // to pewnie nie jest potrzebne...
    that.words = 0; //ani to...
}

Tab_bit &Tab_bit::operator = (const Tab_bit &other)
{
    if(this == &other) return *this;

    length = other.length;
    for(int i = 0; i < words; i++) tab[i] = other.tab[i];

    return *this;
}

Tab_bit &Tab_bit::operator = (Tab_bit &&other)
{
    if(this == &other) return *this;

    length = other.length;
    tab = other.tab;
    other.tab = nullptr;
    other.length = 0; // to pewnie nie jest potrzebne...

    return *this;
}

bool Tab_bit::operator[](int i) const
{
    checkRange(i);
    return read(i);
}

Tab_bit::Ref Tab_bit::operator[](int i)
{
    checkRange(i);
    return Tab_bit::Ref(this, i);
}

inline int Tab_bit::getLength() const
{
    return length;
}

bool Tab_bit::read(int i) const
{
    checkRange(i);
    int index = i / wordSize;
    int rest = i % wordSize;
    return bool((tab[index] >> rest) % 2);
}

bool Tab_bit::write(int i, bool b)
{
    checkRange(i);
    word temp = 1;
    int index = i / wordSize; //ktore slowo
    int rest = i % wordSize;  //ktory bit w slowie

    temp = temp << rest;

    if(b) tab[index] = tab[index] | temp;
    else tab[index] = tab[index] & (~temp);

    return bool((tab[index] >> rest) % 2);
}

void Tab_bit::checkRange(int i) const
{
    if(i < 0 || i >= length) throw std::string("Out of range!!!");
}

Tab_bit::~Tab_bit()
{
    delete[] tab;
}

Tab_bit operator | (const Tab_bit &a, const Tab_bit &b)
{
    const Tab_bit *maxim;
    int minLength = std::min(a.words, b.words);

    if(a.words > b.words) maxim = &a;
    else maxim = &b;

    Tab_bit result(maxim->getLength());

    for(int i = 0; i < minLength; i++) result.tab[i] = a.tab[i] | b.tab[i];


    return result;

}

Tab_bit &operator |= (Tab_bit &a, const Tab_bit &b)
{
    const Tab_bit *maxim;
    int minLength = std::min(a.words, b.words);

    if(a.words > b.words) maxim = &a;
    else maxim = &b;

    Tab_bit result(maxim->getLength());

    for(int i = 0; i < minLength; i++) result.tab[i] = a.tab[i] | b.tab[i];
    a = result;

    return a;
}


Tab_bit operator & (const Tab_bit &a, const Tab_bit &b)
{
    const Tab_bit *maxim;
    int minLength = std::min(a.words, b.words);

    if(a.words > b.words) maxim = &a;
    else maxim = &b;

    Tab_bit result(maxim->getLength());

    for(int i = 0; i < minLength; i++) result.tab[i] = a.tab[i] & b.tab[i];


    return result;

}

Tab_bit &operator &= (Tab_bit &a, const Tab_bit &b)
{
    const Tab_bit *maxim;
    int minLength = std::min(a.words, b.words);

    if(a.words > b.words) maxim = &a;
    else maxim = &b;

    Tab_bit result(maxim->getLength());

    for(int i = 0; i < minLength; i++) result.tab[i] = a.tab[i] & b.tab[i];
    a = result;

    return a;
}
Tab_bit operator ^ (const Tab_bit &a, const Tab_bit &b)
{
    const Tab_bit *maxim;
    int minLength = std::min(a.words, b.words);

    if(a.words > b.words) maxim = &a;
    else maxim = &b;

    Tab_bit result(maxim->getLength());

    for(int i = 0; i < minLength; i++) result.tab[i] = a.tab[i] ^ b.tab[i];


    return result;

}
Tab_bit &operator ^= (Tab_bit &a, const Tab_bit &b)
{
    const Tab_bit *maxim;
    int minLength = std::min(a.words, b.words);

    if(a.words > b.words) maxim = &a;
    else maxim = &b;

    Tab_bit result(maxim->getLength());

    for(int i = 0; i < minLength; i++) result.tab[i] = a.tab[i] ^ b.tab[i];
    a = result;

    return a;
}

Tab_bit operator ~ (const Tab_bit &a)
{
    Tab_bit result = a;

    result.tab[0] = ~a.tab[0];
    for(int i = 0; i < a.words; i++) result.tab[i] =  ~a.tab[i];


    return result;
}

std::istream &operator >> (std::istream &in, Tab_bit &tb)
{
    std::string str = "";
    in >> str;

    Tab_bit temp(int(str.size()));

    tb = temp;

    for(int i = 0; i < tb.length; i++)
    {
        if (str[i] == '0') tb.write(tb.length - (i + 1), 0);
        else if (str[i] == '1') tb.write(tb.length - (i + 1), 1);
        else throw std::string("Bit should be '0' or '1' only!");
    }
    return in;


}
std::ostream &operator << (std::ostream &out, const Tab_bit &tb)
{
    for(int i = tb.length - 1; i >= 0; i--)
    {
        out << "|" << tb[i];
    }
    out << "|";

    return out;
}

