#pragma once
#include "Globals.h"
#include "Entity.h"

class CameraManager
{
public:
	//the game object thing the camera follows
	Entity* target;

	void update();
};

