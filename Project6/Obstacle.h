#pragma once
#include "Entity.h"
class Obstacle :
	public Entity
{
private:
	float w, h;
public:
	Obstacle();
	~Obstacle();

	void setWH(float w, float h);

	//override draw
	virtual void draw();
};

