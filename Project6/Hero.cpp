#include "Hero.h"
#include "Globals.h"


Hero::Hero()
{
	animation = NULL;
	faceRight = true;
}


Hero::~Hero()
{
}

void Hero::setAnimation(Animation* animation){
	this->animation = animation;
}

void Hero::shoot(){
	Bullet* bullet = new Bullet();
	bullet->setRenderer(renderer);
	bullet->setXY(position.x, position.y);
	bullet->angle = rand() % 360;//rand gives value between 0 and max int value, modulus to control it to give numbers between 0-359
	bullet->movementSpeed = 200;//200px per second

	//add to list of entities
	Entity::entities->push_back(bullet);

	SoundManager::soundManager.playSound("laser");
}


void Hero::update(float dt){
	//TODO
	//add new movement stuff
	if (velocity.x > 0)
		faceRight = true;
	if (velocity.x < 0)
		faceRight = false;

	//lazy friction force to apply to acceleration
	Vector friction(-0.5 * (velocity.x), -0.5 * (velocity.y));

	acceleration.x += friction.x;
	acceleration.y += friction.y;

	//update movement based on velocity
	updateMovement(dt);

	if (animation != NULL)
		animation->update(dt);
}
void Hero::draw(){
	if (animation != NULL){
		if (faceRight)
			animation->draw(position.x - Globals::camera.x, position.y - Globals::camera.y);
		else
			animation->draw(position.x - Globals::camera.x, position.y - Globals::camera.y, true);
	}
}
