#pragma once
#include <SDL.h>

class StaticImage
{
public:
	//basic information
	int frameWidth, frameHeight;
	SDL_Texture* titleLogoTexture; //reference to texture
	SDL_Renderer* renderer; //reference to renderer
	
	StaticImage();
	StaticImage(SDL_Texture* texture, SDL_Renderer* renderer, int frameWidth, int frameHeight);
	void draw(int x, int y);
	void draw(int x, int y, float scale);
	void draw(int x, int y, bool flip);
	void draw(int x, int y, float scale, bool flip);
};

