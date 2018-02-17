#include "stdafx.h"
#include "DWyswietl.h"

void CDWyswietl::rysuj(CDWyswietl *ekran)
{
}

SDL_Renderer *CDWyswietl::wpiszRend()
{
	return _renderer;
}

SDL_Window *CDWyswietl::wpiszWindow()
{
	return _window;
}

SDL_Texture * CDWyswietl::wpiszText()
{
	return _tex;
}



CDWyswietl::CDWyswietl()
{
	
}

CDWyswietl::CDWyswietl(int q)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("OKienko", 100, 100, _SCREEN_WIDTH,
		_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	_renderer = SDL_CreateRenderer(_window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}



CDWyswietl::~CDWyswietl()
{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
}


void CDWyswietl::start()
{
	SDL_RenderClear(_renderer);
	SDL_Texture *background = loadTexture("Tlo2.bmp", _renderer);

	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	renderTexture(background, _renderer, 0, 0);

	SDL_RenderPresent(_renderer);
	
	SDL_DestroyTexture(background);
}

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void CDWyswietl::logSDLError(const std::string & msg)
{
	std::fstream os;
	os.open("konsola.txt", std::ios::app);
	os << msg << " error: " << SDL_GetError() << std::endl;
	os.close();
}

/**
* Loads a BMP image into a texture on the rendering device
* @param file The BMP image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture * CDWyswietl::loadTexture(const std::string & file, SDL_Renderer * ren)
{
	_renderer=ren;
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture *texture = nullptr;
	//Load the image
	SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(ren, loadedImage);
		SDL_FreeSurface(loadedImage);	
	}
	return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void CDWyswietl::renderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y)
{
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(ren, tex, NULL, &dst);
}


