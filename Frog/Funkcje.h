#pragma once
#include "stdafx.h"

void logSDLError(std::ostream &os, const std::string &msg);
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void rysuj(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);