#include "IdleGameState.h"


IdleGameState::IdleGameState()
{
}


IdleGameState::~IdleGameState()
{
}

void IdleGameState::update(float dt){
	idleTimer -= dt;
	if (idleTimer <= 0){
		done = true;
	}
}
void IdleGameState::render(){
	if (entity != NULL){
		SDL_SetRenderDrawColor(Globals::renderer, 0, 255, 0, 255);
		SDL_Rect idleStateRect = { entity->position.x - 10 - Globals::camera.x, entity->position.y - 10 - Globals::camera.y, 20, 20 };
		SDL_RenderFillRect(Globals::renderer, &idleStateRect);
	}
}
bool IdleGameState::onEnter(){
	idleTimer = rand() % 1 + 1;//1-10 seconds of idle time
	done = false;

	return true;
}
bool IdleGameState::onExit(){
	return true;
}
std::string IdleGameState::getStateID(){
	return "idleState";
}