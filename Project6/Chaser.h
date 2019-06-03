#pragma once
#include "Entity.h"
#include "GameStateMachine.h"
#include "IdleGameState.h"
#include "ChaseGameState.h"
#include "Animation.h"

class Chaser :
	public Entity
{
public:
	GameStateMachine gsm;
	Entity* target = NULL;
	Animation* animation;

	Chaser();
	~Chaser();

	//override
	virtual void update(float dt);
	virtual void draw();
};



