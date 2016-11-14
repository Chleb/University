// Pawel Meller (241711)
// C++ course 2015, lab02

#include<iostream>
#include<cmath>

#include "odcinek.hpp"

odcinek::odcinek (punkt p, punkt q) {
    if (p.wspx()==q.wspx() && p.wspy()==q.wspy())
        throw std::string("nie można utworzyć odcinka o zerowej długości");

    a = p;
    b = q;
}

odcinek::odcinek (const odcinek &o) {
    a = o.pkta();
    b = o.pktb();
}

odcinek & odcinek::operator= (const odcinek &o) {
    a = o.pkta();
    b = o.pktb();
}

void odcinek::przesun (double dx, double dy) {
  a.przesun(dx, dy);
  b.przesun(dx, dy);
}

punkt odcinek::pkta () const { return a; }

punkt odcinek::pktb () const { return b; }

double odcinek::dlugosc () const {
    return odleglosc(a, b);
}

bool odcinek::zawiera (const punkt &p) const {
    punkt m = punkt(a.wspx()+1, a.wspy()+1);
    odcinek r1(a, m);
    odcinek r2(m, b);
    return (lezy_w_polplaszczynie(p, *this) == 0)
        && (lezy_w_polplaszczynie(p, r1) <= 0.0f)
        && (lezy_w_polplaszczynie(p, r2) <= 0.0f);
}

punkt odcinek::srodek () const {
    double x = (a.wspx() + b.wspx()) / 2;
    double y = (a.wspy() + b.wspy()) / 2;
    return punkt(x, y);
}

int lezy_w_polplaszczynie (const punkt &p, const odcinek &o) {
    return (p.wspx() - o.pktb().wspx())
        * (o.pkta().wspy() - o.pktb().wspy())
        - (o.pkta().wspx() - o.pktb().wspx())
        * (p.wspy() - o.pktb().wspy());
}

double iloczyn_skalarny (const odcinek &p, const odcinek &q) {
    double
        x1 = p.pktb().wspx() - p.pkta().wspx(),
        x2 = q.pktb().wspx() - q.pkta().wspx(),
        y1 = p.pktb().wspy() - p.pkta().wspy(),
        y2 = q.pktb().wspy() - q.pkta().wspy();
    return (x1 * x2 + y1 * y2) / ( sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2) );
}

bool rownolegle (const odcinek &p, const odcinek &q) {
    return iloczyn_skalarny(p, q) == -1;
}

bool prostopadle (const odcinek &p, const odcinek &q) {
    return iloczyn_skalarny(p, q) == 0;
}

punkt przeciecie (const odcinek &p, const odcinek &q) {
    double
        ax = p.pkta().wspx(),
        ay = p.pkta().wspy(),
        bx = p.pktb().wspx(),
        by = p.pktb().wspy(),
        cx = q.pkta().wspx(),
        cy = q.pkta().wspy(),
        dx = q.pktb().wspx(),
        dy = q.pktb().wspy();

    double
        d1 = ((by-ay)*(dx-cx)-(dy-cy)*(bx-ax)),
        d2 = ((dy-cy)*(bx-ax)-(by-ay)*(dx-cx));

    if (d1 == 0 || d2 == 0)
        throw std::string("odcinki są równoległe");

    double x = ((bx-ax)*(dx*cy-dy*cx)-(dx-cx)*(bx*ay-by*ax)) / d1;
    double y = ((dy-cy)*(bx*ay-by*ax)-(by-ay)*(dx*cy-dy*cx)) / d2;

    punkt i(x,y);

    if (!p.zawiera(i) || !q.zawiera(i))
        throw std::string("odcinki nie przecinają się");

    return i;
}

std::ostream & operator<< (std::ostream &os, const odcinek &o) {
    return os << "<" << o.pkta() << ", " << o.pktb() << ">";
}
