#pragma once
#include <SDL.h>
class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	virtual void update(SDL_Event* event) = 0; //abstract function
};

