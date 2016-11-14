#include<iostream>
#include<cmath>

// Pawel Meller (241711)
// C++ course 2015, lab02

#include "trojkat.hpp"

trojkat::trojkat (punkt p, punkt q, punkt r) {
    if (lezy_w_polplaszczynie(p, odcinek(q,r)) == 0)
        throw std::string("nie można utworzyć odcinka ze współliniowych punktów");

    a = p;
    b = q;
    c = r;
}

trojkat::trojkat (const trojkat &t) {
    a = t.pkta();
    b = t.pktb();
    c = t.pktc();
}

trojkat & trojkat::operator= (const trojkat &t) {
    a = t.pkta();
    b = t.pktb();
    c = t.pktc();
}

void trojkat::przesun (double dx, double dy) {
  a.przesun(dx, dy);
  b.przesun(dx, dy);
  c.przesun(dx, dy);
}

punkt trojkat::pkta () const { return a; }

punkt trojkat::pktb () const { return b; }

punkt trojkat::pktc () const { return c; }

double trojkat::obwod () const {
    return odleglosc(a,b) + odleglosc(b,c) + odleglosc(c,a);
}

bool trojkat::zawiera (const punkt &p) const {
    bool b1, b2, b3;

    b1 = lezy_w_polplaszczynie(p, odcinek(a,b)) < 0.0f;
    b2 = lezy_w_polplaszczynie(p, odcinek(b,c)) < 0.0f;
    b3 = lezy_w_polplaszczynie(p, odcinek(c,a)) < 0.0f;

    return (b1 && b2 && b3);
}

punkt trojkat::srodek () const {
    return punkt( (a.wspx()+b.wspx()+c.wspx())/3, (a.wspy()+b.wspy()+c.wspy())/3 );
}

bool rozlaczne (const trojkat &t1, const trojkat &t2) {
    return !(t1.zawiera(t2.pkta()) || t1.zawiera(t2.pktb()) || t1.zawiera(t2.pktc()))
        && !(t2.zawiera(t1.pkta()) || t2.zawiera(t1.pktb()) || t2.zawiera(t1.pktc()));
}

bool zawiera_sie_w (const trojkat &t1, const trojkat &t2) {
    return t2.zawiera(t1.pkta()) && t2.zawiera(t1.pktb()) && t2.zawiera(t1.pktc());
}

std::ostream & operator<< (std::ostream &os, const trojkat &t) {
    return os << "<" << t.pkta() << ", " << t.pktb() << ", " << t.pktc() << ">";
}
