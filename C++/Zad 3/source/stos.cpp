#include "stos.hpp"
#include <string.h>
#include <iostream>

// ten konstruktor rzuca wyjatek gdy rozmiar <= 0
Stos::Stos(int pojemnosc) : pojemnosc(pojemnosc), ile(0)
{
	if (pojemnosc <= 0)
		throw std::string("nie można utworzyć stosu o pojemnosci niedodatniej");
	elementy = new std::string[pojemnosc];
}

// konstruktor kopiujacy
Stos::Stos(const Stos& s) : pojemnosc(s.pojemnosc)
{
	Stos(s.pojemnosc);
	ile = s.ile;
	memcpy(elementy, s.elementy, ile);
}
// konstruktor przenoszacy
Stos::Stos(Stos&& s) : pojemnosc(s.pojemnosc), ile(s.ile)
{
	elementy = s.elementy;

	s.ile = 0;
	s.elementy = nullptr;
}
// konstruktor inicjalizujacy stos za pomoca listy napisow
Stos::Stos(std::initializer_list<std::string> lista) : pojemnosc(2*lista.size() + 1)
{
	Stos(2*lista.size() + 1);

	for (auto iter = lista.begin(); iter < lista.end(); ++iter)
		wloz(*iter);
}
// moze rzucic wyjatek przepelnienia stosu
void Stos::wloz(std::string element)
{
	if (ile == pojemnosc)
		throw std::string("przepelnienie stosu");

	elementy[ile++] = element;
}
// moze rzucic wyjatek gdy stos jest pusty
std::string Stos::sciagnij(void)
{
	if (ile == 0)
		throw std::string("stos pusty");

	return elementy[--ile];
}
// moze rzucic wyjatek gdy stos jest pusty
std::string Stos::sprawdz(void)
{
	if (ile == 0)
		throw std::string("stos pusty");

	return elementy[ile-1];
}
// zwraca ilosc elementow przechowywanych na stosie
int Stos::rozmiar(void)
{
	return ile;
}
// zwalnia pamiec
Stos::~Stos()
{
	delete[] elementy;
}