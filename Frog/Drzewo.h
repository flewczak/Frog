#pragma once
#include "Nieruchome.h"
class CDrzewo :
	public CNieruchome
{
private:
	int _szer;
	int _wys;
public:
	CDrzewo();
	CDrzewo(int x, int y);
	~CDrzewo();

	int dajSzer();

	int dajWys();

	int gdzieX();
	int gdzieY();
	bool zderzenie(CFigura * Figura);
};

