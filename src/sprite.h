#pragma once
#include "SDL.h"

/*!
Basic drawable sprite
*/
typedef struct Sprite
{
	SDL_Texture* texture;
	SDL_Rect sourceRect;
} Sprite;

Sprite LoadSprite(const char* path);

void FreeSprite(Sprite sprite);
