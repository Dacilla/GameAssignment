#include "StaticImage.h"


StaticImage::StaticImage()
{
}

StaticImage::StaticImage(SDL_Texture* texture, SDL_Renderer* renderer, int frameWidth, int frameHeight){
	this->titleLogoTexture = texture;
	this->renderer = renderer;
	this->frameHeight = frameHeight;
	this->frameWidth = frameWidth;
	
}

void StaticImage::draw(int x, int y){
	//get current frame clipping region
	SDL_Rect clip;
	clip.w = frameWidth;
	clip.h = frameHeight;

	//set up destination triangle
	SDL_Rect dest = { x, y, frameWidth, frameHeight };
	//draw
	SDL_RenderCopy(renderer, titleLogoTexture, &clip, &dest);
}

void StaticImage::draw(int x, int y, float scale){
	//get current frame clipping region
	SDL_Rect clip;
	clip.w = frameWidth;
	clip.h = frameHeight;

	//set up destination triangle
	SDL_Rect dest = { x, y, frameWidth*scale, frameHeight*scale };
	//draw
	SDL_RenderCopy(renderer, titleLogoTexture, &clip, &dest);
}

void StaticImage::draw(int x, int y, bool flip){
	//get current frame clipping region
	SDL_Rect clip;
	clip.w = frameWidth;
	clip.h = frameHeight;

	//set up destination triangle
	SDL_Rect dest = { x, y, frameWidth, frameHeight };

	//flip flag
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	if (flip)
		flipType = SDL_FLIP_HORIZONTAL;

	//draw
	SDL_RenderCopyEx(renderer, titleLogoTexture, &clip, &dest, 0, NULL, flipType); //last three variables are angle, rotation center, flip flag

}

void StaticImage::draw(int x, int y, float scale, bool flip){
	//get current frame clipping region
	SDL_Rect clip;
	clip.w = frameWidth;
	clip.h = frameHeight;

	//set up destination triangle
	SDL_Rect dest = { x, y, frameWidth*scale, frameHeight*scale };

	//flip flag
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	if (flip)
		flipType = SDL_FLIP_HORIZONTAL;

	//draw
	SDL_RenderCopyEx(renderer, titleLogoTexture, &clip, &dest, 0, NULL, flipType);

}
