#include "GameControllerHandler.h"


GameControllerHandler::GameControllerHandler()
{
	//how many joysticks are connected? Remember joystick includes gamepads, joysticks, steering wheels etc
	int numJoySticks = SDL_NumJoysticks();

	//loop through joysticks
	for (int joyStickID = 0; joyStickID < numJoySticks; joyStickID++){
		//check if each joystick can be considered a "game Controller" ie similar in design to xbox controller
		if (SDL_IsGameController(joyStickID)){
			//if it is, open this controller
			controller = SDL_GameControllerOpen(joyStickID);
			//we are done now
			break;
		}
	}
}


GameControllerHandler::~GameControllerHandler()
{
	//close controller off if we have one
	if (controller != NULL)
		SDL_GameControllerClose(controller);
}


void GameControllerHandler::update(SDL_Event* event){
	//any face button on the controller will make player jump

	//detects controller and any disconnections
	if (controller != NULL && SDL_GameControllerGetAttached(controller))
	{
		//get joystickID
		SDL_JoystickID joystickID = SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller));

		//check for controller event
		if (event->cdevice.which == joystickID)
		{
			//what kind of event

			//unplugged
			if (event->type == SDL_CONTROLLERDEVICEREMOVED)
			{
				SDL_GameControllerClose(controller);
				controller = NULL;
				return;
			}

			//button pressed
			if (event->type == SDL_CONTROLLERBUTTONDOWN)
			{
				//face button press
				if (event->cbutton.button == SDL_CONTROLLER_BUTTON_A || event->cbutton.button == SDL_CONTROLLER_BUTTON_B || event->cbutton.button == SDL_CONTROLLER_BUTTON_X || event->cbutton.button == SDL_CONTROLLER_BUTTON_Y)
				{
					//jump
				}

			}

		}
	}
}

void GameControllerHandler::updateSticksAndDPads(){
	if (controller != NULL && SDL_GameControllerGetAttached(controller)){
		//read left stick x and y axes
		Sint16 axisX = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX); //neg are left, pos are right
		Sint16 axisY = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY); //neg are up, pos are down

		//deadzone
		int deadzone = 10000;

		//check stick direction
		//Up
		if (axisX < -deadzone || SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_DPAD_UP))
		{
			//jump
		}

	}
}