#include "engine.h"
#include "SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Forward function declarations
void Update(float dt);
void RenderFrame(float dt);

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 576

/*!
Basic drawable sprite
*/
typedef struct Sprite
{
	SDL_Texture* texture;
	SDL_Rect sourceRect;
} Sprite;

// Street texture
Sprite street;

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

//=============================================================================
int main(int argc, char* argv[])
{
	if (!InitPliers())
	{
		return 1;
	}

	if (!CreateWindow("The Game", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		return 1;
	}

	street = LoadSprite("assets/cyberpunk-street.png");

	// Push functions to the game loop
	StartLoop(Update, RenderFrame);

	SDL_DestroyTexture(street.texture);
	CleanUp();
	return 0;
}

//=============================================================================

SDL_Rect rect = {0, 0, 64, 64};
float xPos = 0;

void Update(float dt)
{
	xPos += 512 * dt;
	rect.x = (float)(xPos + 0.5f);

	int winWidth, winHeight;
	SDL_GetWindowSize(gWindow, &winWidth, &winHeight);

	if (rect.x > winWidth)
	{
		
		xPos = -rect.w;
		rect.y += rect.h / 2;
	}

	if (rect.y > winHeight)
	{
		rect.y = -(rect.h / 2);
	}

	if (IsKeyDown(SDL_SCANCODE_ESCAPE))
		ExitGame();
}

void RenderFrame(float interpolation)
{
	// Clear screen
	SDL_SetRenderDrawColor(gRenderer, 65, 105, 225, 255);
	SDL_RenderClear(gRenderer);

	int pixelAmp = 3;
	SDL_Rect backgroundRect = {
		0,
		0,
		street.sourceRect.w * pixelAmp,
		street.sourceRect.h * pixelAmp
	};
	SDL_RenderCopy(gRenderer, street.texture, NULL, &backgroundRect);

	// TODO: Get rid of this
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(gRenderer, &rect);
}