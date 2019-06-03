#pragma once
#include "Entity.h"
class Wall :
	public Entity
{
private:
	float w, h;

public:
	Wall();
	~Wall();

	void setWH(float w, float h);

	//override
	virtual void draw();
};

