#include "stdafx.h"
#include "Pociag.h"
#include "Avatar.h"


CPociag::CPociag()
{
}


CPociag::~CPociag()
{
}



CPociag::CPociag(int x, int y, int predX, int predY)
{
	CFigura::_Punkt->wpiszWspolrzedne(x, y);
	CRuchome::zmianaPredkosci(predX, predY);
	_szer=120;
	_wys=20;
}

int CPociag::dajSzer()
{
	int szer = _szer;
	return szer;
}

int CPociag::dajWys()
{
	int wys = _wys;
	return wys;
}

void CPociag::przesun()
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

int CPociag::gdzieX()
{
	int x = _Punkt->dajX();
	return x;
}

int CPociag::gdzieY()
{
	int y = _Punkt->dajY();
	return y;
}

bool CPociag::zderzenie(CFigura * Figura)
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
		A->zmienZycie(0);
		return true;
}
