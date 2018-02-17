#include "stdafx.h"
#include "DDrzewo.h"


CDDrzewo::CDDrzewo()
{
}


CDDrzewo::~CDDrzewo()
{
	SDL_DestroyTexture(_tex);
}

CDDrzewo::CDDrzewo(CDWyswietl * ekran, CFigura * drzewo)
{
	_window = ekran->wpiszWindow();
	_renderer = ekran->wpiszRend();
	_tex = CDDrzewo::loadTexture("drzewo.bmp", _renderer);
	_wskObiekt = drzewo;
}

void CDDrzewo::rysuj(CDWyswietl * ekran)
{
	SDL_Renderer *rend = ekran->wpiszRend();

	int x = _wskObiekt->gdzieX();
	int y = _wskObiekt->gdzieY();

	CDWyswietl::renderTexture(_tex, CDWyswietl::_renderer, x, y);

}
