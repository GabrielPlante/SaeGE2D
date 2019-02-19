#include "LifeForm.h"

constexpr float deltaAngle = 0.1f;

int LifeForm::idCount = 0;

LifeForm::LifeForm(double x, double y, int speed, int healthPoint, int radius, Friendliness friendliness,
	double directionAngle, double rotatingSpeed, int sightRange, float sightArea)
	:Entity(x, y), baseSpeed{ speed }, actualSpeed{ speed }, healthPoint{ healthPoint }, radius{ radius }, friendliness{ friendliness },
	facingDirection{ facingDirection }, rotatingSpeed{ rotatingSpeed }, sightRange{ sightRange },
	sightArea{ sightArea }, id{ idCount }
{
	idCount++;
}

void LifeForm::render(SDL_Renderer* renderer, const Camera& camera) const {
	constexpr int halfLenght{ 40 };
	constexpr int height{ 30 };

	//healtbar (temporary)
	SDL_SetRenderDrawColor(renderer, 230, 0, 0, 200);
	Position<> relativePosition{ camera.absoluteToRelative(static_cast<long>(position.x), static_cast<long>(position.y)) };
	for (int width = 0; width < 3; width++) {
		SDL_RenderDrawLine(renderer, relativePosition.x - halfLenght, relativePosition.y - height + width,
			relativePosition.x + static_cast<int>(halfLenght * (healthPoint * 2.0 / baseHealtPoint - 1)), relativePosition.y - height + width);
	}

	//Render the weapon
	if (inHandWeapon)
		inHandWeapon->render(renderer, camera, *this);
}

bool LifeForm::refresh() {
	if (inHandWeapon)
		inHandWeapon->refresh();

	if (isTurning) {//Treat hard turn (turning without moving)
		const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastMovement).count() };
		if (rawRotation(directionAngle.get(), rotatingSpeed, deltaTime))
			isTurning = false;
		timeAtLastMovement = std::chrono::high_resolution_clock::now();
	}
	//Turning prevent from moving
	else if (!(destination.getCoordinate() == position)) {
		//If it's moving or attacking and out of range
		if (isAttacking && inHandWeapon && position.distanceSquared(destination.getCoordinate()) < pow(inHandWeapon->getRange(), 2)) {
			if (destination.getEntity())
				attack(destination.getEntity());
			isAttacking = false;
			clearDestination();
		}
		else {
			Angle angle = position.angle(destination.getCoordinate());
			if (angle.get() < facingDirection.get() - deltaAngle && angle.get() > facingDirection.get() + deltaAngle)
				facingDirection = angle;
			const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastMovement).count() };
			rawMovement(destination, actualSpeed, deltaTime);
			timeAtLastMovement = std::chrono::high_resolution_clock::now();

		}
	}
	return !isAlive();
}

bool LifeForm::rawMovement(const Destination& destination, const int speed, const long long deltaTime) {
	constexpr double dividingSpeedFactor{ 1000 * 1000 };//This will divide the speed of every lifeform in the game;
	//The division of the operation to get the movement according to x and y
	const double dividingMovementFactor = sqrt(pow(destination.getCoordinate().x - position.x, 2) + pow(destination.getCoordinate().y - position.y, 2)) * dividingSpeedFactor;
	//We fist calculate the x movement so we can check if the destination.getCoordinate() is reached
	const double movementX = (destination.getCoordinate().x - position.x) * deltaTime * speed / dividingMovementFactor;
	if (movementX > abs(destination.getCoordinate().x - position.x)) {//If the destination.getCoordinate() is reached
		position.x = destination.getCoordinate().x;
		position.y = destination.getCoordinate().y;
		return true;
	}
	else {
		position.x += movementX;
		position.y += (destination.getCoordinate().y - position.y) * deltaTime * speed / dividingMovementFactor;
		return false;
	}
}

bool LifeForm::rawRotation(Angle directionAngle, double rotatingSpeed, const long long deltaTime) {
	constexpr double PI{ 3.14159265 };
	constexpr double dividingRotateFactor{ 10*1000 };
	rotatingSpeed *= deltaTime / dividingRotateFactor;

	double angleDifference = directionAngle.difference(facingDirection);

	int angleSign = 1;//Sign of the angle (1 or -1)
	if (angleDifference != 0)
		angleSign = static_cast<int>(abs(angleDifference) / angleDifference);

	if (abs(angleDifference) < rotatingSpeed) {//check if the lifeform finish rotating
		facingDirection.set(directionAngle);
	}
	else {
		facingDirection.add(rotatingSpeed * angleSign);//Rotate the correct way
	}
	if (directionAngle == facingDirection) {//If the turn is finished, we declare it as such
		return true;
	}
	return false;
}

void LifeForm::setDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	this->destination = destination;
	setRotatingDestination(destination);
}

void LifeForm::setRotatingDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	timeAtLastMovement = std::chrono::high_resolution_clock::now();
	directionAngle = position.angle(destination.getCoordinate());
	isTurning = true;
}

void LifeForm::attack(LifeForm* lifeForm) {
	if (inHandWeapon) {
		//If the target is out of range
		if (position.distanceSquared(lifeForm->getPosition()) > pow(inHandWeapon->getRange(), 2)){
			setDestination(lifeForm);
			isAttacking = true;
		}
		else {
			Angle angle = position.angle(lifeForm->getPosition());
			if (angle.get() - deltaAngle > facingDirection.get() || angle.get() + deltaAngle < facingDirection.get()) {
				setDestination(lifeForm);
				isAttacking = true;
			}
			else {
				inHandWeapon->attack(this);
			}
		}
	}
}

bool LifeForm::isInSight(const Position<double>& entity) const {
	constexpr double PI = 3.14159265;
	Angle angleEntityPlayer = facingDirection.difference(position.angle(entity));
	angleEntityPlayer.add(0);
	return (angleEntityPlayer.get() <= sightArea || angleEntityPlayer.get() >= 2 * PI - sightArea);
}

bool LifeForm::takeDamage(int amount) {
	healthPoint -= amount;
	return !isAlive();
}

LifeForm::~LifeForm()
{
}
