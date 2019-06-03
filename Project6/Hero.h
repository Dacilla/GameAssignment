#pragma once
#include "Entity.h"
#include "Animation.h"
#include "Bullet.h"
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

	void shoot();

	//override
	virtual void update(float dt);
	virtual void draw();
};

