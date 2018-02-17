#pragma once
#include "Ruchome.h"
class CSamochod :
	public CRuchome
{
private:
	int _szer;
	int _wys;
public:
	static int samochodyZderzenia;
	CSamochod();
	~CSamochod();
	CSamochod(int x, int y, int predX, int predY);

	int dajSzer();

	int dajWys();

	void przesun();
	int gdzieX();
	int gdzieY();
	bool zderzenie(CFigura *Figura);
	
};

