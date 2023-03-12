#include "engine.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Forward function declarations
void Update(float dt);
void RenderFrame(float dt);
SDL_Texture* LoadSprite(const char* path);

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360

// Testing sprite
SDL_Texture* sprite;
int spriteWidth, spriteHeight;

//=============================================================================
int main(int argc, char* argv[])
{
	if (!InitSDL())
	{
		return 1;
	}

	if (!CreateWindow("The Game", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		return 1;
	}
	
	// Load sprite
	sprite = LoadSprite("assets/kenney_piratepack/ship.png");
	SDL_QueryTexture(sprite, NULL, NULL, &spriteWidth, &spriteHeight);

	// Push functions to the game loop
	StartLoop(Update, RenderFrame);

	// Delete texture
	if (sprite)
		SDL_DestroyTexture(sprite);

	DeinitSDL();
	return 0;
}

//=============================================================================

void Update(float dt)
{
	// Change subsystem of project from Windows to Console
	// in order to see the stderr output
	if (IsKeyDown(SDL_SCANCODE_ESCAPE))
		ExitGame();
}

void RenderFrame(float interpolation)
{
	// Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0x3a, 0x2b, 0x3b, 255);
	SDL_RenderClear(gRenderer);

	// Draw sprite in the center of the screen
	const SDL_Rect spriteRect = {
		WINDOW_WIDTH / 2 - spriteWidth / 2,
		WINDOW_HEIGHT / 2 - spriteHeight / 2,
		spriteWidth,
		spriteHeight
	};
	SDL_RenderCopy(gRenderer, sprite, NULL, &spriteRect);
}

SDL_Texture* LoadSprite(const char* path)
{

	SDL_Texture* texture = IMG_LoadTexture(gRenderer, path);
	if (texture == NULL)
	{
		fprintf(stderr, "IMG_LoadTexture error: %s\n", IMG_GetError());
		return NULL;
	}

	return texture;
}
