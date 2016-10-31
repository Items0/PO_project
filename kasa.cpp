#include "stdafx.h"
#include "kasa.h"


using namespace std;
float kasa::iteruj()
{
	float saldo = 0;
	cout << "--------------------------------------------" << endl;
	cout << " Nr" << "\t\t" << "Nazwa" << "\t\t" << "Wartosc" << endl;
	for (int i = 0; i < tablica.size(); i++)
	{
		cout << " " << i << "\t\t"; 
		tablica[i].wyswietl();
		saldo += tablica[i].wartosc;
	}
	cout << "--------------------------------------------" << endl;
	return saldo;
}
void kasa::dodaj_konto()
{
	konto nowe;
	string odp;
	cout << "Podaj nowa nazwe: ";
	cin >> nowe.nazwa;
	cout << "Podaj nowe saldo: ";
	cin >> nowe.wartosc;
	cout << "Typ? Pracownik/Student [p/s]? ";
	cin >> odp;
	if (odp == "s")
		nowe.rodzaj = konto::typy_konta::student; // co to jest za typ ?
	if (odp == "p")
		nowe.rodzaj = konto::typy_konta::pracownik;
	tablica.push_back(nowe);
}

void kasa::usun_konto()
{
	int numer;
	iteruj();
	cout << "Nr konta do usuniecia: ";
	cin >> numer;
	if (numer >= 0 && numer <= tablica.size())
	{
		if (tablica[numer].wartosc == 0)
			tablica.erase(tablica.begin() + numer);
		else
			cout << "Saldo != 0" << endl;
	}
	else
	{
		cout << "Numer niepoprawny"<< endl;
	}

}

void kasa::przelew()
{
	int wybor;
	int numer_Z;
	int numer_Na;
	float ile;
	cout << " 1. Z zewnatrz \n 2. Pomiedzy kontami \n";
	cin >> wybor;
	switch (wybor)
	{
		case 1:
		{
			iteruj();
			cout << "Wybierz konto: ";
			cin >> numer_Na;
			cout << "Kwota: ";
			cin >> ile;
			tablica[numer_Na] += ile;
			break;
		}
		case 2:
		{
			iteruj();
			cout << "Z konta: ";
			cin >> numer_Z;
			cout << "Kwota: ";
			cin >> ile;
			tablica[numer_Z] -= ile; // sprawdz i zablokuj opcje przelania na te samo konto
			cout << "Na konto: ";
			cin >> numer_Na;
			try
			{
				if (tablica[numer_Na].rodzaj == konto::typy_konta::student || tablica[numer_Z].rodzaj == konto::typy_konta::student)
				{
					string wyjatek1 = "Studenci nie moga uczestniczyc w transakcji pozyczki";
					throw wyjatek1;
				}
				else
				{
					if (numer_Na != numer_Z)
					{
						tablica[numer_Na] += ile;
						tablica[numer_Z] -= ile;
					}
					else
					{
						string wyjatek2 = "Odbiorca jest adresatem, error!";
						throw wyjatek2;
					}

				}
			}
			catch (string obj)
			{
				cout << obj << endl;
			}
			break;
		}
		default:
		{
			cout << "Zla wartosc" << endl;
		}
	}
}

void kasa::wyswietl_saldo()
{
	//float saldo = iteruj();
	cout << "Saldo: \t\t\t\t" << iteruj() << endl;
}

void kasa::transakcja()
{
	float price;
	cout << " #Numer\t\tNazwa\t\tCena" << endl;
	for (int i = 0; i < tablica.size(); i++)
	{
		cout << " " << i << "\t\t" << tablica[i].nazwa << "\t\t";
		cin >> price;
		tablica[i] -= price;
	}
}
