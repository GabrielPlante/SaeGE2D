#include "LifeForm.h"


LifeForm::LifeForm(double x, double y, int speed, int healthPoint, double directionAngle, double rotatingSpeed)
	:Entity(x, y), baseSpeed{ speed }, actualSpeed{ speed }, healthPoint{ healthPoint },
	directionAngle{ directionAngle }, rotatingSpeed{ rotatingSpeed }
{
}

bool LifeForm::refresh() {
	if (isMoving)
		move(destination);
	return false;
}

bool LifeForm::move(const IntPosition& destination) {
	if (directionAngle == facingDirection) {
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
	else {
		rotate(directionAngle, rotatingSpeed);
		return false;
	}
}

void LifeForm::rotate(double directionAngle, double rotatingSpeed) {
	constexpr double PI = 3.14159265;
	double angleDifference = directionAngle - facingDirection;
	if (angleDifference < -PI)//First make 4 cases 2
		angleDifference += 2 * PI;
	else if (angleDifference > PI)
		angleDifference -= 2 * PI;

	int angleSign = 1;//Sign of the angle (1 or -1)
	if (angleDifference != 0)
		angleSign = static_cast<int>(abs(angleDifference) / angleDifference);

	if (abs(angleDifference) < rotatingSpeed) {//check if the lifeform finish rotating
		facingDirection = directionAngle;
		timeAtLastMovement = SDL_GetTicks();
	}
	else {
		facingDirection += rotatingSpeed * angleSign;//Rotate the correct way
		if (facingDirection > 2 * PI)//Check if we are in the good range [0-2PI]
			facingDirection -= 2 * PI;
		else if (facingDirection < 0)
			facingDirection += 2 * PI;
	}
}

void LifeForm::setDestination(int x, int y) {
	if (x != position.x || y != position.y) {
		destination.x = x;
		destination.y = y;
		timeAtLastMovement = SDL_GetTicks();//So the refresh function triger a movement
		directionAngle = position.angle(IntPosition(x, y));

		isMoving = true;
	}
}

LifeForm::~LifeForm()
{
}
