#include "stdafx.h"
#include "Avatar.h"
#include "Pociag.h"


CAvatar::CAvatar()
{
}


CAvatar::~CAvatar()
{
}

CAvatar::CAvatar(int x, int y, int predX, int predY)
{
	CFigura::_Punkt->wpiszWspolrzedne(x, y);
	CRuchome::zmianaPredkosci(predX, predY);
	_szer = 20;
	_wys = 20;
	_zycie = 4;
	_koniec = 1;
}

int CAvatar::dajSzer()
{
	int szer = _szer;
	return szer;
}

int CAvatar::dajWys()
{
	int wys = _wys;
	return wys;
}

void CAvatar::przesun()
{
	SDL_Event zdarzenie;
	SDL_PollEvent(&zdarzenie);

	int x = _Punkt->dajX();
	int y = _Punkt->dajY();
	if (y >= 360) {
		_koniec = 0;
	}

	if (zdarzenie.type == SDL_KEYDOWN)
	{

		if (zdarzenie.key.keysym.sym == SDLK_RIGHT)
		{
			_poprzX = x;
			_poprzY = y;

			x = x + _predkoscX;
			_Punkt->wpiszWspolrzedne(x, y);
		}
		else if (zdarzenie.key.keysym.sym == SDLK_LEFT)
		{
			_poprzX = x;
			_poprzY = y;

			x = x - _predkoscX;
			_Punkt->wpiszWspolrzedne(x, y);
		}
		else if (zdarzenie.key.keysym.sym == SDLK_UP)
		{
			_poprzX = x;
			_poprzY = y;

			y = y - _predkoscY;
			_Punkt->wpiszWspolrzedne(x, y);
		}
		else if (zdarzenie.key.keysym.sym == SDLK_DOWN)
		{
			_poprzX = x;
			_poprzY = y;

			y = y + _predkoscY;
			_Punkt->wpiszWspolrzedne(x, y);
		}

	}


}

int CAvatar::gdzieX()
{
	int x = _Punkt->dajX();
	return x;
}

int CAvatar::gdzieY()
{
	int y = _Punkt->dajY();
	return y;
}
bool CAvatar::zderzenie(CFigura * Figura)
{
	return false;
}

void CAvatar::zmienZycie(bool zycie)
{
	//dodawania
	if (zycie == 1) {
		_zycie = _zycie + 1;
	}
	//odejmowanie
	else {
		_zycie = _zycie - 1;
		_Punkt->wpiszWspolrzedne(210, 0);
	}

}

int CAvatar::zwrocZycie()
{
	return _zycie;
}

int CAvatar::dajPoprzX()
{
	return _poprzX;
}

int CAvatar::dajPoprzY()
{
	return _poprzY;
}

bool CAvatar::koniecGry()
{
	return _koniec;
}



