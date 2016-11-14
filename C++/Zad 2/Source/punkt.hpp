// Pawel Meller (241711)
// C++ course 2015, lab02

class punkt {
private:
    double x, y;
public:
    punkt ();
    punkt (double a, double b);
    punkt (const punkt &p);
    punkt & operator= (const punkt &p);
public:
    void przesun (double dx, double dy);
    double wspx () const;
    double wspy () const;
};

double odleglosc (const punkt &p1, const punkt &p2);

std::ostream & operator<< (std::ostream &os, const punkt &p);
