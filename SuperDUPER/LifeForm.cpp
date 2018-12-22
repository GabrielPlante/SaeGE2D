#include "LifeForm.h"


LifeForm::LifeForm(double x, double y, int speed, int healthPoint, double directionAngle, double rotatingSpeed)
	:Entity(x, y), baseSpeed{ speed }, actualSpeed{ speed }, healthPoint{ healthPoint },
	directionAngle{ directionAngle }, rotatingSpeed{ rotatingSpeed }
{
}

bool LifeForm::refresh() {
	if (isMoving) {
		if (isTurning)
			rotate(directionAngle, rotatingSpeed);
		else
			move(destination, actualSpeed);
	}
	return false;
}

bool LifeForm::move(const Destination& destination, const int speed) {
	constexpr double dividingSpeedFactor{ 1000 * 1000 };//This will divide the speed of every lifeform in the game;
	//The division of the operation to get the movement according to x and y
	const double dividingMovementFactor = sqrt(pow(destination.getCoordinate().x - position.x, 2) + pow(destination.getCoordinate().y - position.y, 2)) * dividingSpeedFactor;
	//To get a movement independant of framerate
	const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastMovement).count() };
	//We fist calculate the x movement so we can check if the destination.getCoordinate() is reached
	const double movementX = (destination.getCoordinate().x - position.x) * deltaTime * speed / dividingMovementFactor;
	if (movementX > abs(destination.getCoordinate().x - position.x)) {//If the destination.getCoordinate() is reached
		position.x = destination.getCoordinate().x;
		position.y = destination.getCoordinate().y;
		isMoving = false;
		return true;
	}
	else {
		position.x += movementX;
		position.y += (destination.getCoordinate().y - position.y) * deltaTime * speed / dividingMovementFactor;
		timeAtLastMovement = std::chrono::high_resolution_clock::now();
		return false;
	}
}

void LifeForm::rotate(double directionAngle, double rotatingSpeed) {
	constexpr double PI{ 3.14159265 };
	constexpr double dividingRotateFactor{ 10*1000 };
	const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastMovement).count() };
	rotatingSpeed *= deltaTime / dividingRotateFactor;
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
	}
	else {
		facingDirection += rotatingSpeed * angleSign;//Rotate the correct way
		if (facingDirection > 2 * PI)//Check if we are in the good range [0-2PI]
			facingDirection -= 2 * PI;
		else if (facingDirection < 0)
			facingDirection += 2 * PI;
	}
	if (directionAngle == facingDirection)//If the turn is finished, we declare it as such
		isTurning = false;
	timeAtLastMovement = std::chrono::high_resolution_clock::now();
}

void LifeForm::setDestination(const Destination destination) {
	this->destination = destination;
	timeAtLastMovement = std::chrono::high_resolution_clock::now();//Initialise movement timer
	directionAngle = position.angle(destination.getCoordinate());
	isMoving = true;
	isTurning = true;
}

LifeForm::~LifeForm()
{
}
