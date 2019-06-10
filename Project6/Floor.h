#pragma once
#include "Entity.h"
class Floor :
	public Entity
{
private:
	const long w = 100000, h = 500;
public:
	Floor();
	~Floor();

	virtual void draw();
};

