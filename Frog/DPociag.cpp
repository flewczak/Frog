#include "stdafx.h"
#include "DPociag.h"


CDPociag::CDPociag()
{
}


CDPociag::~CDPociag()
{
	SDL_DestroyTexture(_tex);
}

CDPociag::CDPociag(CDWyswietl *ekran, CFigura *pociag)
{
	_window = ekran->wpiszWindow();
	_renderer = ekran->wpiszRend();
	_tex = CDPociag::loadTexture("pociag.bmp", _renderer);
	_wskObiekt = pociag;
}

void CDPociag::rysuj(CDWyswietl * ekran)
{
	SDL_Renderer *rend = ekran->wpiszRend();

	int x = _wskObiekt->gdzieX();
	int y = _wskObiekt->gdzieY();

	CDWyswietl::renderTexture(_tex, CDWyswietl::_renderer, x, y);

}
