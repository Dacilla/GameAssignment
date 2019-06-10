#include "Floor.h"


Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::draw()
{
	//position and size
	SDL_Rect floorRect = { position.x, position.y, w, h };
	//colour
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	//draw
	SDL_RenderFillRect(renderer, &floorRect);
}
