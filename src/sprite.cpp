#include "sprite.h"
#include "engine.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

//=============================================================================
Sprite LoadSprite(const char* path)
{
	Sprite retSprite = {NULL, {0, 0, 0, 0}};

	SDL_Texture* texture = IMG_LoadTexture(gRenderer, path);
	if (texture == NULL)
	{
		fprintf(stderr, "IMG_LoadTexture error: %s\n", IMG_GetError());
		return retSprite;
	}

	int w, h;
	if (SDL_QueryTexture(texture, NULL, NULL, &w, &h) < 0)
	{
		fprintf(stderr, "SDL_QueryTexture error: %s\n", SDL_GetError());
		return retSprite;
	}

	retSprite.texture = texture;
	retSprite.sourceRect = {0, 0, w, h};
	
	return retSprite;
}

void FreeSprite(Sprite sprite)
{
	if (sprite.texture)
		SDL_DestroyTexture(sprite.texture);
}
