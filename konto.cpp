#include "stdafx.h"
#include "konto.h"


void konto::wyswietl()
{
	cout << nazwa << "\t\t" << wartosc << endl;
}

void konto::operator-=(float a)
{
	wartosc -= a;
}

void konto::operator+=(float a)
{
	wartosc += a;
}