#include "Ball.h"
#include "Globals.h"


Ball::Ball()
{
	velocity.x = 0;
	velocity.y = 0;
	gravity = 400;
}


Ball::~Ball()
{

}


void Ball::update(float dt){
	//they are in the air, adhere to gravity
	if (position.y < 600){
		//keep setting gravity as a constant force/accelerator
		acceleration.y = gravity;
	}
	else
	{
		acceleration.y = 0;
		//on the ground
		//if velocity is pushing the ball down but we hit ground, then reverse the velocity for bounce
		if (velocity.y > 0.1){
			velocity.y = velocity.y * -0.9;//take 10% of energy when hitting stuff
		}
		else
		{
			velocity.y = 0;
			velocity.x = velocity.x*0.99;//applying friction to velocity
		}
	}

	//bouncing off walls
	//    left wall and moving left            right wall and moving right
	if ((position.x <= 0 && velocity.x <= 0) || (position.x >= 800 && velocity.x >= 0))
	{
		velocity.x = velocity.x*-0.9; //reverse the x velocity direction
	}


	updateMovement(dt);

}
void Ball::draw(){
	SDL_SetRenderDrawColor(renderer, 163, 73, 164, 255);
	SDL_Rect ballRect = { position.x - 25 - Globals::camera.x, position.y - 25 - Globals::camera.y, 50, 50 };

	SDL_RenderFillRect(renderer, &ballRect);
}