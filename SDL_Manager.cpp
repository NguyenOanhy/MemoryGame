#include "SDL_Manager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>

SDL_Manager::SDL_Manager (int SCREEN_WIDTH, int SCREEN_HEIGHT) {

	this->SCREEN_WIDTH = SCREEN_WIDTH;
	this->SCREEN_HEIGHT = SCREEN_HEIGHT;
	this->window = NULL;
	this->renderer = NULL;
}

bool SDL_Manager::init () {

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		this->window = SDL_CreateWindow( "Memory Game", 0, 0, this->SCREEN_WIDTH, this->SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( this->window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			SDL_SetWindowTitle (this->window, "Memory Game");

			//Create renderer for window
			this->renderer = SDL_CreateRenderer( this->window, -1, SDL_RENDERER_ACCELERATED );
			if( this->renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				 //Initialize SDL_mixer
				 if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

int SDL_Manager::getWidth () {

	return this->SCREEN_WIDTH;
}

int SDL_Manager::getHeight () {

	return this->SCREEN_HEIGHT;
}

SDL_Renderer* SDL_Manager::getRenderer () {

	return this->renderer;
}

SDL_Window* SDL_Manager::getWindow () {

	return this->window;
}

SDL_Manager::~SDL_Manager () {

	//Destroy window
	SDL_DestroyRenderer( this->renderer );
	SDL_DestroyWindow( this->window );

	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

