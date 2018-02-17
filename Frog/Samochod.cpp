#include "stdafx.h"
#include "Samochod.h"


CSamochod::CSamochod()
{
	
}



CSamochod::~CSamochod()
{
}

CSamochod::CSamochod(int x, int y, int predX, int predY)
{
	CFigura::_Punkt->wpiszWspolrzedne(x,y);
	CRuchome::zmianaPredkosci(predX, predY);
	_szer = 60;
	_wys = 20;

}

int CSamochod::dajSzer()
{
	int szer = _szer;
	return szer;
}

int CSamochod::dajWys()
{
	int wys = _wys;
	return wys;
}


void CSamochod::przesun()
{
	int x = _Punkt->dajX();
	int y = _Punkt->dajY();
	if (x <= 600) {
		x = x + _predkoscX;
		y = y + _predkoscY;
	}
	else {
		x = _szer*(-1)+0;
	}
	_Punkt->wpiszWspolrzedne(x, y);
}

int CSamochod::gdzieX()
{
	int x=_Punkt->dajX();
	return x;
}

int CSamochod::gdzieY()
{
	int y = _Punkt->dajY();
	return y;
}

bool CSamochod::zderzenie(CFigura * Figura)
{
	CAvatar *A = dynamic_cast<CAvatar*>(Figura);
		int xA = _Punkt->dajX();
		int yA = _Punkt->dajY();

		int xF = Figura->gdzieX();
		int yF = Figura->gdzieY();

		int szerA = dajSzer();
		int wysA = dajWys();


		int szerF = A->dajSzer();
		int wysF = A->dajWys();

		int minXA = xA;
		int maxXA = xA + szerA;
		int minYA = yA;
		int maxYA = yA + wysA;

		int minXF = xF;
		int maxXF = xF + szerF;
		int minYF = yF;
		int maxYF = yF + wysF;

		bool warunek = minXA > maxXF || maxXA<minXF
			|| minYA>maxYF || maxYA < minYF;
		if (warunek)
		{
			return false;
		}
		samochodyZderzenia = samochodyZderzenia - 1;
		if (samochodyZderzenia != 0) {
			int x = A->dajPoprzX();
			int y = A->dajPoprzY();
			A->wpiszWspPunktu(x, y);
			return false;
		}
		A->zmienZycie(0);
		samochodyZderzenia = 2;
		return true;

}


