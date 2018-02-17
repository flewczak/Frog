#pragma once
//#include "stdafx.h"
#include <fstream>
#include <SDL.h>
#include "Figura.h"
class CDWyswietl
{
protected:
	const int _SCREEN_WIDTH = 600;
	const int _SCREEN_HEIGHT = 600;
	
protected:
	SDL_Window *_window=NULL;
	SDL_Renderer *_renderer=NULL;
	SDL_Texture *_tex;
	CFigura *_wskObiekt;
	
public:
	virtual void rysuj(CDWyswietl *ekran);
	SDL_Renderer *wpiszRend();
	SDL_Window *wpiszWindow();
	SDL_Texture *wpiszText();
	void start();
	void logSDLError( const std::string &msg);
	SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
	void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);

	CDWyswietl();
	CDWyswietl(int q);
	~CDWyswietl();

};

