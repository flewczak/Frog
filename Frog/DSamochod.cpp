#include "stdafx.h"
#include "DSamochod.h"


CDSamochod::CDSamochod()
{
}

CDSamochod::CDSamochod(CDWyswietl *ekran, CFigura *samochod)
{
	_window = ekran->wpiszWindow();
	_renderer = ekran->wpiszRend();
	_tex = CDSamochod::loadTexture("prostokat.bmp", _renderer);
	_wskObiekt = samochod;
}





CDSamochod::~CDSamochod()
{
	SDL_DestroyTexture(_tex);
}


void CDSamochod::rysuj(CDWyswietl *ekran)
{
	SDL_Renderer *rend = ekran->wpiszRend();
	
	int x = _wskObiekt->gdzieX();
	int y = _wskObiekt->gdzieY();

	CDWyswietl::renderTexture(_tex, CDWyswietl::_renderer, x, y);
	
}
