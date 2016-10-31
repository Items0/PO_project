#pragma once
#include <string>
#include <iostream>
using namespace std;
class konto
{
public:
	string nazwa;
	float wartosc;
	enum typy_konta
	{
		pracownik, student
	};
	typy_konta rodzaj;
	void wyswietl();
	void operator-=(float a);
	void operator+=(float a);
};