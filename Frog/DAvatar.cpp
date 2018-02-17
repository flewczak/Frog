#include "stdafx.h"
#include "DAvatar.h"


CDAvatar::CDAvatar()
{
}


CDAvatar::~CDAvatar()
{
}

CDAvatar::CDAvatar(CDWyswietl * ekran, CFigura * avatar)
{
	_window = ekran->wpiszWindow();
	_renderer = ekran->wpiszRend();
	_tex = CDAvatar::loadTexture("zaba.bmp", _renderer);
	_wskObiekt = avatar;
}

void CDAvatar::rysuj(CDWyswietl * ekran)
{

	SDL_Renderer *rend = ekran->wpiszRend();

	int x = _wskObiekt->gdzieX();
	int y = _wskObiekt->gdzieY();

	CDWyswietl::renderTexture(_tex, CDWyswietl::_renderer, x, y);

	CAvatar *A = dynamic_cast <CAvatar*>(_wskObiekt);
	int liczZyc = A->zwrocZycie();
	SDL_Texture	*textura=NULL;

	if (liczZyc == 1) {
		textura = CDAvatar::loadTexture("1.bmp", _renderer);
	}
	if (liczZyc == 2) {
		textura = CDAvatar::loadTexture("2.bmp", _renderer);
	}
	if (liczZyc == 3) {
		textura = CDAvatar::loadTexture("3.bmp", _renderer);
	}
	if (liczZyc == 4) {
		textura = CDAvatar::loadTexture("4.bmp", _renderer);		
	}
	if (liczZyc == 5) {
		textura = CDAvatar::loadTexture("5.bmp", _renderer);
	}
	if (liczZyc == 6) {
		textura = CDAvatar::loadTexture("6.bmp", _renderer);
	}
	if (liczZyc == 7) {
		textura = CDAvatar::loadTexture("7.bmp", _renderer);
	}
	if (liczZyc >= 8) {
		textura = CDAvatar::loadTexture("8.bmp", _renderer);
	}

	CDWyswietl::renderTexture(textura, CDWyswietl::_renderer, 500, 0);
	SDL_Texture	*textura2 = CDAvatar::loadTexture("zycie.bmp", _renderer);
	CDWyswietl::renderTexture(textura2, CDWyswietl::_renderer, 530, 0);
	SDL_RenderPresent(CDWyswietl::_renderer);
}
