// [Kurs C++] Zadanie 5
//
// Implementacja klasy List2Way wraz z krótkim
//            programem testowym.
//
// Autor: Tomasz Musiała

#include "list2way.hpp"
#include <iostream>


int main()
{
    //test MyList
    MyList ml{1,2,3,4};
    ml.write();
    std::cout << ml[2] << "\n"; //test indeksowania
    ml.del(3);
    ml.write();

    //test List2Way

    List2Way a{1,2,3,4,5};
    List2Way b = a;
    std::cout << "a = " << a;

    b--;
    std::cout << "\nb--\n";
    std::cout << "b = " << b;

    --b;
    std::cout << "\n--b\n";
    std::cout << "b = " << b;

    a = b + 100;
    std::cout << "\na = b + 100\n";
    std::cout << "a = " << a;

    b = 100 + a + 7;
    std::cout << "\nb = 100 + a + 7\n";
    std::cout << "b = " << b;

    std::cout << "\na = " << a;
    std::cout << "first of a = "<< a.first() << "\n";
    std::cout << "last of a = "<< a.last() << "\n";
    std::cout << "length of a = "<< a.getLength() << "\n";



    return 0;
}
