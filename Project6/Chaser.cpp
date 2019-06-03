#include "Chaser.h"


Chaser::Chaser()
{
	IdleGameState* idle = new IdleGameState();
	idle->entity = this;
	gsm.push(idle);
}


Chaser::~Chaser()
{
}
void Chaser::update(float dt){
	gsm.update(dt);
	GameState* currentState = gsm.gameStates.back();
	if (currentState->done){
		if (currentState->getStateID() == "idleState"){
			//add chase state to the top of the stack
			ChaseGameState* newState = new ChaseGameState();
			newState->entity = this;
			newState->target = target;

			gsm.push(newState);
		}
		else if (currentState->getStateID() == "chaseState"){
			//assuming this state is never on bottom, we'll just kill it
			gsm.pop();
		}
	}

	updateMovement(dt);

	animation->update(dt);
}

void Chaser::draw(){
	gsm.render();
	if (animation != NULL)
		animation->draw(position.x - Globals::camera.x, position.y - Globals::camera.y);
}
