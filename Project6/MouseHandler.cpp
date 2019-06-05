#include "MouseHandler.h"


MouseHandler::MouseHandler()
{
	leftMouseHeld = false;
}


MouseHandler::~MouseHandler()
{
}

void MouseHandler::update(SDL_Event* event){
	//check for left click
	if ((event->type == SDL_MOUSEBUTTONDOWN) && (event->button.button == SDL_BUTTON_LEFT)){
		leftMouseHeld = true; // player is allowed to click anywhere on the screen
	}
}
