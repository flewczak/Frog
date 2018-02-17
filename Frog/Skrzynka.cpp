#include "stdafx.h"
#include "Skrzynka.h"


CSkrzynka::CSkrzynka()
{
}

CSkrzynka::CSkrzynka(int x, int y)
{
	CFigura::_Punkt->wpiszWspolrzedne(x, y);
	_szer=20;
	_wys=20;
	_zmiana = 0;
}


CSkrzynka::~CSkrzynka()
{
}

int CSkrzynka::dajSzer()
{
	int szer = _szer;
	return szer;
}

int CSkrzynka::dajWys()
{
	int wys = _wys;
	return wys;
}

int CSkrzynka::gdzieX()
{
	int x = _Punkt->dajX();
	return x;
}

int CSkrzynka::gdzieY()
{
	int y = _Punkt->dajY();
	return y;
}


bool CSkrzynka::zderzenie(CFigura * Figura)
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
	if (_zmiana == 2) {
		return false;
	}

	if (warunek)
	{
		return false;
	}

	if (_zmiana == 1) {
		CAvatar *A = dynamic_cast<CAvatar*>(Figura);
		A->zmienZycie(1);
		_zmiana = 2;
		return false;
	}
	_zmiana = 1;
	xF=xF+ 30;
	yF=yF;
	Figura->wpiszWspPunktu(xF, yF);
	return false;
}

int CSkrzynka::coTo()
{
	return _zmiana;
}
