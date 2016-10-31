#include "stdafx.h"
#include "menu.h"
#include "konto.h"
#include "kasa.h"

void menu::read(kasa & k)
{
	konto nowe;
	fstream uchwyt_IN("plik.txt", ios::in);
	while (uchwyt_IN >> nowe.nazwa >> nowe.wartosc)
		k.tablica.push_back(nowe);
}

void menu::write(kasa & k)
{
	fstream uchwyt_OUT("plik.txt", ios::out | ios::trunc);
	for (int i = 0; i < k.tablica.size(); i++)
		uchwyt_OUT << k.tablica[i].nazwa << " " << k.tablica[i].wartosc << endl;
}


menu::menu()
{
	kasa cash_box;
	read(cash_box);
	int wybor = 0;
	while (wybor != 6)
	{
		cout << "\n 1. Dodaj konto \n 2. Usun konto \n 3. Wykonaj przelew \n 4. Wyswietl stan kasy \n 5. Dokonaj transakcji \n 6. EXIT \n ===> ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
		{
			cash_box.dodaj_konto();
			break;
		}
		case 2:
		{
			cash_box.usun_konto();
			break;
		}
		case 3:
		{
			cash_box.przelew();
			break;
		}
		case 4:
		{
			cash_box.wyswietl_saldo();
			break;
		}
		case 5:
		{
			cash_box.transakcja();
			break;
		}
		case 6:
		{
			break;
		}
		default:
		{
			cout << "Zla wartosc" << endl;
		}
		}
		write(cash_box);
		_getch();
		system("cls");
	}
}
