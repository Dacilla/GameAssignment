#include "Obstacle.h"


Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}

void Obstacle::setWH(float w, float h)
{
	this->w = w;
	this->h = h;
}

void Obstacle::draw()
{
	//position and size
	SDL_Rect obstacleRect = {position.x, position.y, w, h};
	//colour
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	//draw
	SDL_RenderFillRect(renderer, &obstacleRect);
}