#include <iostream>
#include "wyrazenie.hpp"

using namespace std;
using namespace wyr;

int main ()
{
	double A, B;
	wyrazenie* w[5];
	wyrazenie* w1[2];
	wyrazenie* w2[2];
	wyrazenie* w3[4];
	wyrazenie* w4[7];


    cout <<"**** TESTY Z ZADANIA ****" <<endl;

    w[0] = new dodaj(
        new liczba(3),
        new liczba(5)
    );
    w[1] = new dodaj(
        new liczba(2),
        new mnoz(
            new zmienna("x"),
            new liczba(7)
        )
    );
    w[2] = new dziel(
        new dodaj(
            new liczba(3),
            new liczba(5)
        ),
        new dodaj(
            new liczba(2),
            new mnoz(
                new zmienna("x"),
                new liczba(7)
            )
        )
    );
    w[3] = new dziel(
        new mnoz(
            new dodaj(
                new zmienna("x"),
                new liczba(1)
            ),
            new zmienna("x")
        ),
        new liczba(2)
    );
    w[4] = new wyr::sin(
        new mnoz(
            new dodaj(
                new zmienna("x"),
                new liczba(1)
            ),
            new zmienna("x")
        )
    );

    for (int i = 0; i < 5; i++){
        if (i == 1) zmienna::ustal ("x", -0.618);
        cout <<w[i]->opis () <<" = " <<wyr::to_string (w[i]->oblicz ()) <<endl;
        delete w[i];
    }


    cout <<endl <<"**** TEST WYRAZEN ATOMOWYCH ****" <<endl;
    w1[0] = new liczba (-3.75);
    w1[1] = new zmienna ("x");
    zmienna::ustal ("x", 5.5);

    for (int i = 0; i < 2; i++){
        cout <<w1[i]->opis () <<" = " <<wyr::to_string (w1[i]->oblicz ()) <<endl;
        delete w1[i];
    }


    cout <<endl <<"**** TEST OPERATOROW 0-ARGUMENTOWYCH ****" <<endl;
    w2[0] = new e ();
    w2[1] = new pi ();

    for (int i = 0; i < 2; i++){
        cout <<w2[i]->opis () <<" = " <<wyr::to_string (w2[i]->oblicz ()) <<endl;
        delete w2[i];
    }


    cout <<endl <<"**** TEST OPERATOROW 1-ARGUMENTOWYCH ****" <<endl;
    A = -3.75;
    w3[0] = new przec_znak (new liczba(A));
    w3[1] = new wart_bezw (new liczba(A));
    w3[2] = new wyr::sin (new liczba(A));
    w3[3] = new wyr::cos (new liczba(A));

    for (int i = 0; i < 4; i++){
        cout <<w3[i]->opis () <<" = " <<wyr::to_string (w3[i]->oblicz ()) << endl;
        delete w3[i];
    }


    cout <<endl <<" TEST OPERATOROW 2-ARGUMENTOWYCH ****" <<endl;
    A = 3.75; B = 2.5;
    w4[0] = new dodaj (new liczba(A), new liczba(B));
    w4[1] = new odejmij (new liczba(A), new liczba(B));
    A = 8; B = 4;
    w4[2] = new mnoz (new liczba(A), new liczba(B));
    w4[3] = new dziel (new liczba(A), new liczba(B));
    w4[4] = new logarytm (new liczba(A), new liczba(B));
    A = 3; B = 2;
    w4[5] = new modulo (new liczba(A), new liczba(B));
    w4[6] = new potega (new liczba(A), new liczba(B));

    for (int i = 0; i < 7; i++){
        cout <<w4[i]->opis () <<" = " <<wyr::to_string (w4[i]->oblicz ()) <<endl;
        delete w4[i];
    }

}
