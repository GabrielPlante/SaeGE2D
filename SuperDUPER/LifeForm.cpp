#include "LifeForm.h"



LifeForm::LifeForm(double x, double y, int speed, int healthPoint)
	:Entity(x, y)
{
	baseSpeed = speed;
	actualSpeed = speed;
	this->healthPoint = healthPoint;
}

bool LifeForm::refresh() {
	if (isMoving)
		move(destination);
	return false;
}

bool LifeForm::move(const IntPosition& destination) {
	constexpr auto dividingSpeedFactor = 1000;//This will divide the speed of every lifeform in the game;
	//The division of the operation to get the movement according to x and y
	const auto dividingMovementFactor = sqrt(pow(destination.x - position.x, 2) + pow(destination.y - position.y, 2)) * dividingSpeedFactor;
	//To get a movement independant of framerate
	const auto deltaTime = SDL_GetTicks() - timeAtLastMovement;
	//We fist calculate the x movement so we can check if the destination is reached
	const auto movementX = (destination.x - position.x) * deltaTime * actualSpeed / dividingMovementFactor;
	if (movementX > abs(destination.x - position.x)) {//If the destination is reached
		position.x = destination.x;
		position.y = destination.y;
		isMoving = false;
		return true;
	}
	else {
		position.x += movementX;
		position.y += (destination.y - position.y) * deltaTime * actualSpeed / dividingMovementFactor;
		timeAtLastMovement = SDL_GetTicks();
		return false;
	}
}

void LifeForm::setDestination(int x, int y) {
	if (x != position.x || y != position.y) {
		destination.x = x;
		destination.y = y;
		timeAtLastMovement = SDL_GetTicks();//So the refresh function triger a movement
		isMoving = true;
	}
}

LifeForm::~LifeForm()
{
}
