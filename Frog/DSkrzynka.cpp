#include "stdafx.h"
#include "DSkrzynka.h"
#include "Skrzynka.h"


CDSkrzynka::CDSkrzynka()
{
}


CDSkrzynka::~CDSkrzynka()
{
	SDL_DestroyTexture(_tex);
}

CDSkrzynka::CDSkrzynka(CDWyswietl * ekran, CFigura * skrzynka)
{
	_window = ekran->wpiszWindow();
	_renderer = ekran->wpiszRend();
	
	_tex = CDSkrzynka::loadTexture("skrzynka.bmp", _renderer);
	_wskObiekt = skrzynka;
}

void CDSkrzynka::rysuj(CDWyswietl * ekran)
{
	SDL_Renderer *rend = ekran->wpiszRend();

	CSkrzynka *q;
	q = dynamic_cast <CSkrzynka *>(_wskObiekt);
	int warunek = q->coTo();

	if (warunek==1) {
		_tex = CDSkrzynka::loadTexture("moneta.bmp", _renderer);
	}
	if (warunek == 2) {
		_tex = CDSkrzynka::loadTexture("brakMonety.bmp", _renderer);
	}


	int x = _wskObiekt->gdzieX();
	int y = _wskObiekt->gdzieY();

	CDWyswietl::renderTexture(_tex, CDWyswietl::_renderer, x, y);

}
