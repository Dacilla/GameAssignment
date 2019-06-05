#include "Bullet.h"
#include "Globals.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{

}

void Bullet::update(float dt){
	//convert angle in degrees to radians(for trigonometry)
	float angleInRadians = angle / 180 * M_PI;

	velocity.x = movementSpeed*cos(angleInRadians);
	velocity.y = movementSpeed*sin(angleInRadians);

	updateMovement(dt);

}

void Bullet::draw(){
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);//yellow
	SDL_Rect bulletRect = { position.x - 10 - Globals::camera.x, position.y - 10 - Globals::camera.y, 20, 20 };
	SDL_RenderFillRect(renderer, &bulletRect);
}
