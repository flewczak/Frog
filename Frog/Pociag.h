#pragma once
#include "Ruchome.h"
class CPociag :
	public CRuchome
{
private:
	int _szer;
	int _wys;
public:
	CPociag();
	~CPociag();
	CPociag(int x, int y, int predX, int predY);
	int dajSzer();
	int dajWys();
	void przesun();
	int gdzieX();
	int gdzieY();
	bool zderzenie(CFigura *Figura);
	
};

