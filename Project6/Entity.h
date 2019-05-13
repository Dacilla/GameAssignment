#pragma once
#include <SDL.h>
#include <list>

class Entity
{
protected:
	SDL_Renderer* renderer;

public:
	//setup vectors
	Vector position;
	Vector velocity;
	Vector acceleration;

	Entity();
	~Entity();

	void setRenderer(SDL_Renderer* renderer);
	void setXY(float x, float y);
	float getX();
	float getY();

	virtual void update(float dt);
	virtual void updateMovement(float dt);
	virtual void draw();

	static list<Entity*> *enitities;
};

