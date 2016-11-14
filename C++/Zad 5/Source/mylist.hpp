// [Kurs C++] Zadanie 5
//
// Implementacja klasy List2Way wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała

#ifndef MYLIST_HPP_INCLUDED
#define MYLIST_HPP_INCLUDED

#include "tab_bit.hpp"




class MyList
{


    private:


        class MyNode
        {
            private:
                MyNode *next;
                MyNode *prev;
                double value;
                static const int capacity; // wielkośc tablicy węzłów
                static MyNode *NodeTab;    //wskażnik na statyczną tablicę węzłów
                int index; //indeks w NodeTab
                static Tab_bit check; //tablica pomocnicza, 0 - slot wolny, 1 slot zajęty

            public:
                MyNode(MyNode *p, MyNode *n, double val);
               ~MyNode();

                MyNode &getNext(int i); // zwraca referencję do i-tego węzła za bieżącym

                MyNode *addNext(double val); //dodanie węzła za węzłem bieżącym
                MyNode *addPrev(double val); //dodanie węzła przed węzłem bieżącym
                MyNode *addNext(int i, double val);//dodanie węzła i miejsc za węzłem bieżącym
                                                   // (i=0 wstawia bezpośrednio za)
                MyNode *addPrev(int i, double val);//dodanie węzła i miejsc przed węzłem bieżącym
                                                   // (i=0 wstawia bezpośrednio przed)
                MyNode *del();//usunięcie bieżącego węzła
                              //jeżeli węzeł znajdował się na początku lub w środku, metoda zwraca węzeł, który był następny,
                              //wpp poprzedni.
                MyNode *delNext(int i);//usunięcie węzła i miejsc za bieżącym

                double getValue() const;

                void write(); //funkcja testowa wypisująca wartości węzłów począwszy od bieżącego

                MyNode &operator = (const MyNode &other); // przypisanie kopiujące
                MyNode &operator = (const int); // przypisanie wartości


                static void *operator new(size_t);
                static void operator delete(void *);
                operator double() // przeładowanie rzutowanie na double
                {
                    return value;
                }

        };

protected:
    int length;     //długość listy
    MyNode *begin; //wskaźnik na początek listy
    MyNode *end;   //wskaźnik na koniec listy
public:
    MyList();                               //komplet konstruktorów i destruktor
    MyList(MyList const &that);
    MyList(MyList &&that);
    MyList(std::initializer_list<double> l);
    ~MyList();

    void insert(int i, const double val); // wstawia węzeł z wartością na miejsce i-te
    void del(int i);                      //usuwa węzeł z i-tego miejsca
    void write() const;                   //testowe wyświetlanie listy
    double getBegin() const;              //zwraca wartość z początku listy
    double getEnd() const;                //zwraca wartość z końca listy
    int getLength() const;                //zwraca długość listy

    MyList &operator = (const MyList &other); //operator kopiujący
    MyList &operator = (MyList &&other);      //operator przenoszący

    MyNode &operator[](int i);                //indeksowanie
    double operator[](int i) const;



};





#endif // MYLIST_HPP_INCLUDED
