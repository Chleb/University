// Pawel Meller (241711)
// C++ course 2015, lab02

#include <iostream>

#include "trojkat.hpp"

int main () {
    // punkty
    punkt p(1,1), q(3,4);
    p.przesun(-1,-1);
    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "|p,q| = " << odleglosc(p, q) << std::endl;
    std::cout << "|0,q| = " << odleglosc(q, punkt()) << std::endl << std::endl;

    // odcinki
    odcinek a(p, q), b(punkt(0,3), punkt(4,0));
    b.przesun(1,1);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "|a| = " << a.dlugosc() << std::endl;
    std::cout << "a _|_ b = " << prostopadle(a, b) << std::endl;
    std::cout << "a || b = " << rownolegle(a, b) << std::endl;
    std::cout << "midpoint(a) = " << a.srodek() << std::endl;
    std::cout << "midpoint(a) in a = " << a.zawiera(a.srodek()) << std::endl;
    std::cout << "(5,7) in a = " << a.zawiera(punkt(5,7)) << std::endl << std::endl;

    try {
        std::cout << "a ^ b = " << przeciecie(a,b) << std::endl;
        b.przesun(5,5);
        std::cout << "a ^ b = " << przeciecie(a,b) << std::endl;
    } catch (std::string ex) {
        std::cout << ex << std::endl << std::endl;
    }

    // trojkaty
    trojkat t(punkt(0,0), punkt(0,4), punkt(3,0));
    std::cout << "t = " << t << std::endl;
    std::cout << "perimeter(t) = " << t.obwod() << std::endl;
    t.przesun(1, 1);
    std::cout << "t = " << t << std::endl;
    std::cout << "center(t) = " << t.srodek() << std::endl;
    std::cout << "(-1,5) in t = " << t.zawiera(punkt(-1,5)) << std::endl;
    std::cout << "(2,2) in t = " << t.zawiera(punkt(2,2)) << std::endl << std::endl;

    trojkat t1(punkt(-1,1), punkt(0,2), punkt(1,1)),
        t2(punkt(-2,0), punkt(0,3), punkt(2,0));
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;
    std::cout << "t1 in t2 = " << zawiera_sie_w(t1, t2) << std::endl;
    std::cout << "t2 in t1 = " << zawiera_sie_w(t2, t1) << std::endl;
    std::cout << "t2 ^ t1 = " << !rozlaczne(t1, t2) << std::endl << std::endl;

    t1.przesun(4, 5);
    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t1 in t2 = " << zawiera_sie_w(t1, t2) << std::endl;
    std::cout << "t2 ^ t1 = " << !rozlaczne(t1, t2) << std::endl << std::endl;

    return 0;
}
