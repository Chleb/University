// Pawel Meller (241711)
// C++ course 2015, lab02

#include "odcinek.hpp"

class trojkat {
private:
    punkt a, b, c;
public:
    trojkat (punkt a, punkt b, punkt c);
    trojkat (const trojkat &t);
    trojkat & operator= (const trojkat &t);
public:
    void przesun (double dx, double dy);
    punkt pkta () const;
    punkt pktb () const;
    punkt pktc () const;
    double obwod () const;
    bool zawiera (const punkt &p) const;
    punkt srodek () const;
};

bool rozlaczne (const trojkat &t1, const trojkat &t2);
bool zawiera_sie_w (const trojkat &t1, const trojkat &t2);

std::ostream & operator<< (std::ostream &os, const trojkat &t);
