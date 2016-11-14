// [Kurs C++] Zadanie 5
//
// Implementacja klasy List2Way wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała

#ifndef LIST2WAY_HPP_INCLUDED
#define LIST2WAY_HPP_INCLUDED
#include "mylist.hpp"

class List2Way :MyList
{
public:
    List2Way();                                   //zestaw konstruktorów
    List2Way(List2Way const &that);
    List2Way(List2Way &&that);
    List2Way(std::initializer_list<double> l);
    ~List2Way();                                  //destruktor

    List2Way &operator = (const List2Way &other); // przypisanie kopiujące
    List2Way &operator = (List2Way &&other);      //przypisanie przenoszące


    void addEnd(double val);         //dodaj val na koniec
    void addBegin(double val);       //dodaj val na początek
    void delEnd();                   //usuń koniec
    void delBegin();                 //usuń początek
    int getLength() const;           //zwróć długość listy
    double first() const;            //zwróć głowę listy
    double last() const;             //zwróć koniec listy

    List2Way &operator -- ();    //--l usuwa początek l
    List2Way &operator -- (int); //l-- usuwa koniec l

    friend std::ostream &operator << (std::ostream &out, const List2Way &tb);
    friend  List2Way operator + (const double e, const List2Way &l);
    friend  List2Way operator + (const List2Way &l, const double e); //wiem, że ten operator mógłby
                                                                    //należeć do klasy, ale z tego co czytałem
                                                                    //w tym przypadku ładniej jest zachować symetrię


};


#endif // LIST2WAY_HPP_INCLUDED
