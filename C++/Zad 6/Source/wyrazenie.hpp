#ifndef WYRAZENIE_HPP
#define WYRAZENIE_HPP


#include <sstream>
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_E
#define M_E 2.71828182845904523536
#endif

namespace wyr {

template<typename T>
std::string to_string (const T& n)
{
    std::ostringstream stm;
    stm <<n;
    return stm.str ();
}


typedef double T;

class wyrazenie {
public:
	virtual ~wyrazenie () {}

	virtual T oblicz () = 0;
	virtual std::string opis () = 0;
};


class operator_0_arg : public wyrazenie {};


class operator_1_arg : public operator_0_arg {
protected:
	wyrazenie *A;
public:
	operator_1_arg (wyrazenie* _A) : A(_A) {}
	virtual ~operator_1_arg () { delete A; }
};


class operator_2_arg : public operator_1_arg {
protected:
	wyrazenie *B;
public:
	operator_2_arg (wyrazenie* _A, wyrazenie* _B) : operator_1_arg(_A), B(_B) {}
	virtual ~operator_2_arg () { delete B; }
};


///////////////////////////////////////////////////////////
/// Wyrażenia atomowe
///
class liczba : public wyrazenie
{
	T wartosc;
public:
	liczba (T _wartosc) : wartosc(_wartosc) {}

	T oblicz () { return wartosc; }
	std::string opis () { return wyr::to_string (wartosc); }
};


class zmienna : public wyrazenie
{
	static std::vector <std::pair <std::string, T>> Vault;
	std::string symbol;
public:
	zmienna (std::string _symbol) : symbol(_symbol) {}

	T oblicz ();
	std::string opis () { return symbol; }
	static void ustal (std::string symbol, T wartosc);
};


///////////////////////////////////////////////////////////
/// Operatory 0-argumentowe
///
class e : public operator_0_arg
{
public:
	T oblicz () { return M_E; }
	std::string opis () { return "e()"; }
};


class pi : public operator_0_arg
{
public:
	T oblicz () { return M_PI; }
	std::string opis () { return "pi()"; }
};


///////////////////////////////////////////////////////////
/// Operatory 1-argumentowe
///
class przec_znak : public operator_1_arg
{
public:
	przec_znak (wyrazenie *_A) : operator_1_arg(_A) {}

	T oblicz () { return static_cast<T>(-1) * A->oblicz (); }
	std::string opis () { return "przeciwny_znak(" + A->opis () + ")"; }
};


class wart_bezw : public operator_1_arg
{
public:
	wart_bezw (wyrazenie *_A) : operator_1_arg(_A) {}

	T oblicz () { return std::abs (A->oblicz ()); }
	std::string opis () { return "wartosc_bezwzgledna(" + A->opis () + ")"; }
};


class sin : public operator_1_arg
{
public:
	sin (wyrazenie *_A) : operator_1_arg(_A) {}

	T oblicz () { return std::sin (A->oblicz ()); }
	std::string opis () { return "sin(" + A->opis () + ")"; }
};


class cos : public operator_1_arg
{
public:
	cos (wyrazenie *_A) : operator_1_arg(_A) {}

	T oblicz () { return std::cos (A->oblicz ()); }
	std::string opis () { return "cos(" + A->opis () + ")"; }
};


///////////////////////////////////////////////////////////
/// Operatory 2-argumentowe
///
class dodaj : public operator_2_arg
{
public:
	dodaj (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz () { return A->oblicz () + B->oblicz (); }
	std::string opis () { return "(" + A->opis () + " + " + B->opis () + ")"; }
};


class odejmij : public operator_2_arg
{
public:
	odejmij (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz () { return A->oblicz () - B->oblicz (); }
	std::string opis () { return "(" + A->opis () + " - " + B->opis () + ")"; }
};


class mnoz : public operator_2_arg
{
public:
	mnoz (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz () { return A->oblicz () * B->oblicz (); }
	std::string opis () { return "(" + A->opis () + " * " + B->opis () + ")"; }
};


class dziel : public operator_2_arg
{
public:
	dziel (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz ();
	std::string opis () { return "(" + A->opis () + " / " + B->opis () + ")"; }
};


class logarytm : public operator_2_arg
{
public:
	logarytm (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz ();
	std::string opis () { return "log" + B->opis () + "(" + A->opis () + ")"; }
};


class modulo : public operator_2_arg
{
public:
	modulo (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz ();
	std::string opis () { return "(" + A->opis () + " \% " + B->opis () + ")"; }
};


class potega : public operator_2_arg
{
public:
	potega (wyrazenie *_A, wyrazenie *_B) : operator_2_arg(_A, _B) {}

	T oblicz () { return std::pow (A->oblicz (), B->oblicz ()); }
	std::string opis () { return "(" + A->opis () + " ^ " + B->opis () + ")"; }
};


}

#endif
