// Pawel Meller (241711)
// C++ course 2015, lab02

#include<iostream>
#include<cmath>

#include "punkt.hpp"

punkt::punkt (): x(0), y(0) {}

punkt::punkt (double a, double b): x(a), y(b) {}

punkt::punkt (const punkt &p) {
    x = p.wspx();
    y = p.wspy();
}

punkt & punkt::operator= (const punkt &p) {
    x = p.wspx();
    y = p.wspy();
}

void punkt::przesun (double dx, double dy) {
    x += dx;
    y += dy;
}

double punkt::wspx () const { return x; }

double punkt::wspy () const { return y; }

double odleglosc (const punkt &p, const punkt &q) {
    double dx = p.wspx() - q.wspx();
    double dy = p.wspy() - q.wspy();
    return sqrt(dx * dx + dy * dy);
}

std::ostream & operator<< (std::ostream &os, const punkt &p) {
    return os << "(" << p.wspx() << ", " << p.wspy() << ")";
}
