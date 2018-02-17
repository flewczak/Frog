#pragma once
#include "Nieruchome.h"
class CSkrzynka :
	public CNieruchome
{
private:
	int _zmiana;
	int _szer;
	int _wys;
public:
	CSkrzynka();
	CSkrzynka(int x, int y);
	~CSkrzynka();

	int dajSzer();

	int dajWys();

	int gdzieX();
	int gdzieY();
	bool zderzenie(CFigura * Figura);
	int coTo();
};

