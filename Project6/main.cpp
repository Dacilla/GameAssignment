#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>//text to font
#include <SDL_mixer.h>//sound n music
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
	//srand(time(NULL));

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

	//SDL_QueryTexture(titleLogoTexture, NULL, NULL, &sourceRect.w, &sourceRect.h);

	//draw location of the logo
}