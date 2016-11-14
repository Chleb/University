/*
Michal Przystupa
233241

Notatki:
>> nie sprawdzam za kazdym "cin" czy na pewno wpisano liczbe typu int, bo to by istotnie pogorszylo przejrzystosc kodu robie to tylko raz (przy wybieraniu akcji do wykonania)
*/

#include "stos.hpp"
#include <iostream>
#include <limits>

void wypiszMenu();

#define UTWORZ_NOWY_PUSTY_STOS 0
#define WLOZ 1
#define SCIAGNIJ 2
#define SPRAWDZ 3
#define SPRAWDZ_ROZMIAR 4
#define ZAKONCZ 5

using namespace std;

int main(int argc, char const *argv[])
{
	// deklaracja i inicjalizacja danych poczatkowych
	Stos* s = new Stos();
	int zakoncz = 0;
	int wybor, pojemnosc, dlugosc;
	string element;

	// interaktywny program testujacy
	while (!zakoncz)
	{
		wypiszMenu();
		// wczytaj wybor, jesli podano napis nie bedacy liczba rozpocznij petle od poczatku
		cin >> wybor;
		if (cin.fail())
		{
			cout << "Wybierz numer z listy dostepnych opcji";
			// wymazuje flage bledow
			cin.clear();
			// czysci bufor
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// zaleznie od wybory uzytkownika wykonaj jedna z akcji
		switch (wybor)
		{
			case UTWORZ_NOWY_PUSTY_STOS:
				try
				{
					delete s;
					cout << "Podaj pojemnosc nowego stosu" << endl << ">> ";
					cin >> pojemnosc;
					s = new Stos(pojemnosc);
				} 
				catch	(string wyj)
				{
					s = new Stos();
					cout << "Stos powinien miec dodatnia pojemnosc" << endl; 
				}
				break;
			case WLOZ:
				try
				{
					cout << "Podaj element" << endl << ">> ";
					cin.ignore();
					getline(cin, element);
					s->wloz(element);
				} 
				catch	(string wyj) 
				{ 
					cout << "Stos jest juz pelny" << endl; 
				}
				break;
			case SCIAGNIJ:
				try
				{
					element = s->sciagnij();
					cout << "Sciagnieto element: " << element << endl;
				} 
				catch	(string wyj) 
				{ 
					cout << "Stos jest pusty" << endl; 
				}
				break;
			case SPRAWDZ:
				try
				{
					element = s->sprawdz();
					cout << "Element na szczycie: " << element << endl;
				} 
				catch	(string wyj) 
				{ 
					cout << "Stos jest pusty" << endl; 
				}
				break;
			case SPRAWDZ_ROZMIAR:
				cout << "Rozmiar wynosi: " << s->rozmiar() << endl;
				break;
			case ZAKONCZ:
				zakoncz = 1;
				break;
			default:
				cout << "Wybierz numer z listy dostepnych opcji";
				break;
		}
	}

	// zwolnij przydzielone miejsce
	delete s;

	return 0;
}

void wypiszMenu()
{
	cout << endl << "Co chcesz zrobic?:" << endl;
	cout << "0 -> Utworz nowy pusty stos o wybranej pojemnosci" << endl;
	cout << "1 -> Wloz nowy napis na stos" << endl;
	cout << "2 -> Sciagnij napis ze stos" << endl;
	cout << "3 -> Sprawdz jaki napis znajduje sie na szczycie stosu" << endl;
	cout << "4 -> Sprawdz aktualny rozmiar stosu" << endl;
	cout << "5 -> Zakoncz" << endl;
	cout << ">> ";
}