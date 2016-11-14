#ifndef stos_hpp
#define stos_hpp

#include <string>

const int DOMYSLNA_POJEMNOSC = 1;

class Stos
{
private:
	std::string* elementy;
	int ile;
public:
	const int pojemnosc;
	
	// ten konstruktor rzuca wyjatek gdy rozmiar <= 0
	Stos(int pojemnosc = DOMYSLNA_POJEMNOSC);
	// konstruktor kopiujacy
	Stos(const Stos& s);
	// konstruktor przenoszacy
	Stos(Stos&& s);
	// konstruktor inicjalizujacy stos za pomoca listy napisow
	Stos(std::initializer_list<std::string> lista);
	// moze rzucic wyjatek przepelnienia stosu
	void wloz(std::string element);
	// moze rzucic wyjatek gdy stos jest pusty
	std::string sciagnij(void);
	// moze rzucic wyjatek gdy stos jest pusty
	std::string sprawdz(void);
	// zwraca ilosc elementow przechowywanych na stosie
	int rozmiar(void);
	// zwalnia pamiec
	~Stos();
};

#endif