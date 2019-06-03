#pragma once
#include "Entity.h"
class Ball :
	public Entity
{
public:
	float gravity;

	Ball();
	~Ball();

	void update(float dt);
	void draw();
};

