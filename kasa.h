#pragma once
#include "konto.h"
#include <iostream>
#include <vector>
class kasa
{
private:
	float iteruj();
public:
	vector <konto> tablica;
	void dodaj_konto();
	void usun_konto();
	void przelew();
	void wyswietl_saldo();
	void transakcja();
};

