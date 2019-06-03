#pragma once
#include "GameState.h"
#include "Entity.h"
#include <stdlib.h> //for random numbers

class IdleGameStates:
	public GameState
{
public:
	float idleTimer; //1 = 1 second
	Entity* entity = NULL;
	IdleGameStates();
	~IdleGameStates();
	virtual void update(float dt);
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

