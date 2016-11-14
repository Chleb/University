// [Kurs C++] Zadanie 5
//
// Implementacja klasy List2Way wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała

#ifndef LIST2WAY_CPP_INCLUDED
#define LIST2WAY_CPP_INCLUDED
#include "list2way.hpp"

List2Way::List2Way(): MyList()
{}
List2Way::List2Way(List2Way const &that): MyList(that)
{}
List2Way::List2Way(List2Way &&that): MyList(that)
{}
List2Way::List2Way(std::initializer_list<double> l): MyList(l)
{}
List2Way::~List2Way()
{
    this->MyList::~MyList();
}

void List2Way::addEnd(double val)
{
    insert(length, val);
}

void List2Way::addBegin(double val)
{
    insert(0, val);
}

void List2Way::delEnd()
{
    del(length - 1);
}

void List2Way::delBegin()
{
    del(0);
}

int List2Way::getLength() const
{
    return MyList::getLength();
}

double List2Way::first() const
{
    return getBegin();
}

double List2Way::last() const
{
    return getEnd();
}

List2Way &List2Way::operator = (const List2Way &other)
{
    //std::cout << "kopiuję\n";
    this->MyList::operator = (other);
    return *this;
}

List2Way &List2Way::operator = (List2Way &&other)
{
    //std::cout << "przenoszę\n";
    this->MyList::operator = (other);
    return *this;
}

std::ostream &operator << (std::ostream &out, const List2Way &l)
{
    for(int i = 0; i < l.length; i++)
    {
        out << l[i] << ",";
        //std::cout << "i = " << i << "\n";
    }
    out << "\n";

    return out;
}
List2Way operator + (const double e, const List2Way &l)
{
    List2Way res(l);
    res.addBegin(e);
    return res;
}

List2Way operator + (const List2Way &l, const double e)
{
    List2Way res(l);
    res.addEnd(e);
    return res;
}

List2Way &List2Way::operator -- ()
{
    delBegin();
    return *this;
}
List2Way &List2Way::operator -- (int)
{
    delEnd();
    return *this;
}

#endif // LIST2WAY_CPP_INCLUDED
