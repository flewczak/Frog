#include "stdafx.h"
#include "Drzewo.h"


CDrzewo::CDrzewo()
{
	
}
CDrzewo::CDrzewo(int x, int y)
{
	CFigura::_Punkt->wpiszWspolrzedne(x, y);
	_szer=50;
	_wys=20;
}


CDrzewo::~CDrzewo()
{
}

int CDrzewo::dajSzer()
{
	int szer = _szer;
	return szer;
}

int CDrzewo::dajWys()
{
	int wys = _wys;
	return wys;
}

int CDrzewo::gdzieX()
{
	int x = _Punkt->dajX();
	return x;
}

int CDrzewo::gdzieY()
{
	int y = _Punkt->dajY();
	return y;
}


bool CDrzewo::zderzenie(CFigura * Figura)
{
	CAvatar *A = dynamic_cast <CAvatar*>(Figura);

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
	int x = A->dajPoprzX();
	int y = A->dajPoprzY();
	Figura->wpiszWspPunktu(x, y);
	return true;

}
