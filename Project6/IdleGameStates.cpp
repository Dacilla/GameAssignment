#include "IdleGameStates.h"

IdleGameStates::IdleGameStates()
{
}


IdleGameStates::~IdleGameStates()
{
}

void IdleGameStates::update(float dt){
	idleTimer -= dt;
	if (idleTimer <= 0){
		done = true;
	}
}
void IdleGameStates::render(){
	if (entity != NULL){
		SDL_SetRenderDrawColor(Globals::renderer, 0, 255, 0, 255);
		SDL_Rect idleStateRect = { entity->position.x - 10, entity->position.y - 10, 20, 20 };
		SDL_RenderFillRect(Globals::renderer, &idleStateRect);
	}
}
bool IdleGameStates::onEnter(){
	idleTimer = rand() % 10 + 1; // 1 - 10 seconds of idle time
	done = false;
	return true;
}
bool IdleGameStates::onExit(){
	return true;
}
std::string IdleGameStates::getStateID(){
	return "idleState";
}