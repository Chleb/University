// Pawel Meller (241711)
// C++ course 2015, lab02

#include "punkt.hpp"

class odcinek {
private:
    punkt a, b;
public:
    odcinek (punkt a, punkt b);
    odcinek (const odcinek &o);
    odcinek & operator= (const odcinek &o);
public:
    void przesun (double dx, double dy);
    punkt pkta () const;
    punkt pktb () const;
    double dlugosc () const;
    bool zawiera (const punkt &p) const;
    punkt srodek () const;
};

int lezy_w_polplaszczynie (const punkt &p, const odcinek &o);
double iloczyn_skalarny (const odcinek &p, const odcinek &q);
bool rownolegle (const odcinek &p, const odcinek &q);
bool prostopadle (const odcinek &p, const odcinek &q);
punkt przeciecie (const odcinek &p, const odcinek &q);

std::ostream & operator<< (std::ostream &os, const odcinek &o);
