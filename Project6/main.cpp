#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>//text to font
#include <SDL_mixer.h>//sound and music
#include <stdlib.h>
#include <time.h>
#include <list>

#include "InputHandler.h"
#include "KeyboardHandler.h"
#include "StaticImage.h"
#include "Entity.h"
#include "Animation.h"
#include "CameraManager.h"
#include "GameControllerHandler.h"
#include "GameState.h"
#include "GameStateMachine.h"
#include "IdleGameState.h"
#include "IdleGameStates.h"
#include "MouseHandler.h"
#include "SoundManager.h"
#include "Vector.h"
#include "Hero.h"
#include "Obstacle.h"

using namespace std;

//TODO: Create Vectors class

int main(int argc, char** argv){
	srand(time(NULL));

	//initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cout << "SDL Failed: " << SDL_GetError() << endl;
		system("pause");
		return -1;
	}

	//Need to initialise other sub libraries
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
		cout << "sdl image failed: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//INIT sdl ttf
	if (TTF_Init() != 0){
		cout << "sdl ttf failed: " << TTF_GetError() << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}

	//init sdl mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
		cout << "Mixer error: " << Mix_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//render window
	SDL_Window* window = SDL_CreateWindow("Coming soon to Linux", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);

	if (window == NULL) //checks if window actually appeared
	{
		cout << "window failed: " << SDL_GetError() << endl;
		system("pause");
		SDL_Quit(); //cleans up SDL
		return -1;
	}

	//creates renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL) //checks if renderer worked
	{
		cout << "renderer failed: " << SDL_GetError() << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}

	//load image into ram as a surface
	SDL_Surface* titleLogoSurface = SDL_LoadBMP("assets/pokemonlogo.bmp");
	//convert surface into texture
	SDL_Texture* titleLogoTexture = SDL_CreateTextureFromSurface(renderer, titleLogoSurface);
	//delete surcface from memory
	SDL_FreeSurface(titleLogoSurface);

	SDL_Rect sourceRect; // region we want to draw for the title, being 280x103px
	sourceRect.x = 280;
	sourceRect.y = 103;

	SDL_QueryTexture(titleLogoTexture, NULL, NULL, &sourceRect.w, &sourceRect.h);
	/* sourceRect.w = 280;
	sourceRect.h = 103; */

	//draw location of the logo
	SDL_Rect destinationRect;
	destinationRect.x = 600;
	destinationRect.y = 800;
	destinationRect.w = sourceRect.w*2;
	destinationRect.h = sourceRect.h*2;
	

	StaticImage titleImg(titleLogoTexture, renderer, 280, 103);

	//setup game entities
	list<Entity*> entities;
	//point to the list made
	Entity::entities = &entities;

	//build a hero
	Hero* hero = new Hero();
	hero->setRenderer(renderer);
	hero->setXY(200, 200);
	hero->acceleration.x = 200;

	//add to entities list
	entities.push_back(hero);

	//build obstacles
	Obstacle* obstacle = new Obstacle();
	obstacle->setRenderer(renderer);
	obstacle->setXY(400, 400);
	obstacle->setWH(20, 20);

	entities.push_back(obstacle);

	//setup input and keyboard handling
	KeyboardHandler keyboardHandler;

	InputHandler* inputHandler = &keyboardHandler;

	MouseHandler mouseHandler;

	GameControllerHandler controllerHandler;


	//Setup Text
	TTF_Font* font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 16);
	SDL_Color textColour = { 123, 0, 34, 0 };
	//create surface using font, colour, and message
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Not a RomHack!", textColour);
	//convert surface to texture
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	//text destination
	SDL_Rect textDestination;
	textDestination.x = 200;
	textDestination.y = 500; 

	//time management
	Uint32 lastUpdate = SDL_GetTicks();

	bool loop = true;
	while (loop){
		//time management
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		//convert milliseconds into fraction of a second
		float DT = timeDiff / 1000.0;
		//update since last update
		lastUpdate = SDL_GetTicks();

		//poll inputs
		SDL_Event event;
		//loop check for all accepted inputs
		while (SDL_PollEvent(&event)){
			//check if window closed
			if (event.type == SDL_QUIT){
				loop = false;
			}
			//check for esc key
			if (event.type == SDL_KEYDOWN){
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
					loop = false;
				}
			}

			//update input handler
			inputHandler->update(&event);
			mouseHandler.update(&event);
			controllerHandler.update(&event);

		}
			keyboardHandler.updateHeldKeys(); //check for held down keys

			//set drawing colour for renderer
			SDL_SetRenderDrawColor(renderer, 155, 0, 155, 255);
			//clear screen with draw colour
			SDL_RenderClear(renderer);

			//render text on top of everything (last)
			SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

			//render to the screen
			SDL_RenderPresent(renderer);			
	}

	//Clean up
	SDL_DestroyTexture(textTexture);
	SDL_DestroyTexture(titleLogoTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;

}