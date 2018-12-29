#include "LifeForm.h"

int LifeForm::idCount = 0;

LifeForm::LifeForm(double x, double y, int speed, int healthPoint, Friendliness friendliness,
	double directionAngle, double rotatingSpeed, int sightRange, float sightArea)
	:Entity(x, y), baseSpeed{ speed }, actualSpeed{ speed }, healthPoint{ healthPoint }, friendliness{ friendliness },
	facingDirection{ facingDirection }, rotatingSpeed{ rotatingSpeed }, sightRange{ sightRange },
	sightArea{ sightArea }, id{ idCount }
{
	idCount++;
}

bool LifeForm::refresh() {
	if (isTurning)
		rotate(directionAngle, rotatingSpeed);
	switch (actionState)
	{
	/*case ActionState::AtRest:
		break;*/
	case ActionState::Moving:
		move(destination, actualSpeed);
		break;
	case ActionState::Attacking:
		break;
	default:
		break;
	}
	return false;
}

bool LifeForm::move(const Destination& destination, const int speed) {
	if (destination.getCoordinate() == position) {
		actionState = ActionState::AtRest;
		return true;
	}
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
		actionState = ActionState::AtRest;
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
	const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastRotation).count() };
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
	if (directionAngle == facingDirection) {//If the turn is finished, we declare it as such
		isTurning = false;
		if (actionState != ActionState::Moving) {
			timeAtLastMovement = std::chrono::high_resolution_clock::now();
			actionState = ActionState::Moving;
		}
	}
	timeAtLastRotation = std::chrono::high_resolution_clock::now();
}

void LifeForm::setDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	this->destination = destination;
	setRotatingDestination(destination);
	timeAtLastMovement = std::chrono::high_resolution_clock::now();//Initialise movement timer
	actionState = ActionState::AtRest;
}

void LifeForm::setRotatingDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	timeAtLastRotation = std::chrono::high_resolution_clock::now();
	directionAngle = position.angle(destination.getCoordinate());
	isTurning = true;
}

bool LifeForm::isInSight(const Position<double>& entity) const {
	constexpr double PI = 3.14159265;
	double angleEntityPlayer = Position<>::reajustAngle(position.angle(entity) - facingDirection);
	return (angleEntityPlayer <= sightArea || angleEntityPlayer >= 2 * PI - sightArea);
}

LifeForm::~LifeForm()
{
}
