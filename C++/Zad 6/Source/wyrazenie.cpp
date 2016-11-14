#include "wyrazenie.hpp"
using namespace wyr;


typedef std::vector <std::pair <std::string, T>> VT;
VT zmienna::Vault;


T zmienna::oblicz ()
{
	for (VT::iterator i = Vault.begin (); i != Vault.end (); i++)
		if (i->first == symbol)
			return i->second;
	return 0;
}


void zmienna::ustal (std::string symbol, T wartosc)
{
	for (VT::iterator i = Vault.begin (); i != Vault.end (); i++)
		if (i->first == symbol)
		{
			i->second = wartosc;
			return;
		}
	Vault.push_back (make_pair (symbol, wartosc));
}


T dziel::oblicz ()
{
	T b = B->oblicz ();
	if (b == 0)
		throw "Dzielisz przez 0";
	return A->oblicz () / b;
}


T logarytm::oblicz ()
{
	T a = A->oblicz ();
	T b = B->oblicz ();
	if (a <= 0 || b <= 0 || a == 1)
		throw "Logarytm z niewlasciwymi argumentami!";
	return std::log (a) / std::log (b);
}


T modulo::oblicz ()
{
	T b = B->oblicz ();
	if (b == 0)
		throw "Modulo 0!";
	return std::fmod (A->oblicz (), b);
}
