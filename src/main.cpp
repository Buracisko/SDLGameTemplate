#include "engine.h"
#include "sprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Forward function declarations
void Update(float dt);
void RenderFrame(float dt);

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 576

// Street texture
Sprite street;

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

	street = LoadSprite("assets/cyberpunk-street.png");

	// Push functions to the game loop
	StartLoop(Update, RenderFrame);

	FreeSprite(street);
	CleanUp();
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
	SDL_SetRenderDrawColor(gRenderer, 65, 105, 225, 255);
	SDL_RenderClear(gRenderer);

	// Draw sprite (scaled by factor of 3)
	int pixelAmp = 3;
	SDL_Rect backgroundRect = {
		0,
		0,
		street.sourceRect.w * pixelAmp,
		street.sourceRect.h * pixelAmp
	};
	SDL_RenderCopy(gRenderer, street.texture, NULL, &backgroundRect);
}
