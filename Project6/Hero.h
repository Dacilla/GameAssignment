#pragma once
#include "Entity.h"
#include "Animation.h"
#include <stdlib.h>
#include "SoundManager.h"

class Hero : public Entity
{
private:
	Animation* animation;
	bool faceRight; 

public:
	Hero();
	~Hero();

	void setAnimation(Animation* animation);

	//override
	virtual void update(float dt);
	virtual void draw();
};

