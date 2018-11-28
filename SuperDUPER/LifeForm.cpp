#include "LifeForm.h"




LifeForm::LifeForm(double x, double y, int speed)
	:Entity(x, y)
{
	baseSpeed = speed;
	actualSpeed = speed;
}

bool LifeForm::refresh() {
	if (timeAtLastMovement) {
		constexpr auto dividingSpeedFactor = 10000;//This will divide the speed of every lifeform in the game;
		//The division of the operation to get the movement according to x and y
		const double dividingMovementFactor = sqrt(pow(destination.x - position.x, 2) + pow(destination.y - position.y, 2)) * dividingSpeedFactor;
		//To get a movement independant of framerate
		const int deltaTime = SDL_GetTicks() - timeAtLastMovement;
		//We fist calculate the x movement so we can check if the destination is reached
		const double movementX = (destination.x - position.x) * deltaTime / dividingMovementFactor;
		if (movementX > destination.x - position.x) {//If the destination is reached
			position.x = destination.x;
			position.y = destination.y;
			timeAtLastMovement = 0;//0 == no movement
		}
		else {
			position.x += movementX;
			position.y += (destination.y - position.y) * deltaTime / dividingMovementFactor;
			timeAtLastMovement = SDL_GetTicks();
		}
	}
	return false;
}

void LifeForm::setDestination(int x, int y) {
	destination.x = x;
	destination.y = y;
	timeAtLastMovement = SDL_GetTicks();//So the refresh function triger a movement
}

LifeForm::~LifeForm()
{
}
