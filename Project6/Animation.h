#pragma once
#include <SDL.h>

class Animation
{
public:
	//basic information we need
	int numberOfFrames;
	int frameWidth, frameHeight;
	float frameDuration; //how long a frame stays on screen
	SDL_Texture* spriteSheet;//reference to existing texture
	SDL_Renderer* renderer; //reference to our renderer

	//current state of animation
	int currentFrame;//which frame to show on screen
	float frameTimer; //how long has the current frame been on screen

	Animation();
	Animation(SDL_Texture* texture, SDL_Renderer* renderer, int numberOfFrames, int frameWidth, int frameHeight, float frameDuration);
	void update(float dt);
	void draw(int x, int y);
	void draw(int x, int y, float scale);
	void draw(int x, int y, bool flip);
};

