#include "LifeForm.h"
#include "Map.h"

constexpr float deltaAngle = 0.001f;

int LifeForm::idCount = 0;

LifeForm::LifeForm(float x, float y, int speed, int healthPoint, short radius, Friendliness friendliness,
	float directionAngle, float rotatingSpeed, int sightRange, float sightArea)
	:Entity(x, y), baseSpeed{ speed }, actualSpeed{ speed }, healthPoint{ healthPoint }, radius{ radius }, friendliness{ friendliness },
	facingDirection{ directionAngle }, rotatingSpeed{ rotatingSpeed }, sightRange{ sightRange },
	sightArea{ sightArea }, id{ idCount }, previousPosition{ static_cast<long>(x), static_cast<long>(y) }
{
	idCount++;
}

void LifeForm::render(SDL_Renderer* renderer, const Camera& camera) const {
	Entity::render(renderer, camera);
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

bool LifeForm::refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) {
	if (inHandWeapon)
		inHandWeapon->refresh(map, lifeForms, deltaTime);

	if (actionQueue.empty())
		return !isAlive();
	else if (actionQueue.front() == Action::Turn) {//Treat hard turn (turning without moving)
		if (facingDirection.rotate(directionAngle, rotatingSpeed, deltaTime)) {
			actionQueue.pop();
		}
	}
	else if (actionQueue.front() == Action::Attack && inHandWeapon) {
		inHandWeapon->attack(this);
		actionQueue.pop();
	}
	else if (actionQueue.front() == Action::Move) {
		Angle angle = position.angle(destination.getCoordinate());
		if (angle.get() < facingDirection.get() - deltaAngle && angle.get() > facingDirection.get() + deltaAngle)
			facingDirection = angle;
		if (rawMovement(destination, actualSpeed, deltaTime))
			actionQueue.pop();
	}

	checkCollision(map, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)}, radius);

	return !isAlive();
}

bool LifeForm::rawMovement(const Destination& destination, const int speed, float deltaTime) {
	previousPosition.x = static_cast<long>(position.x);
	previousPosition.y = static_cast<long>(position.y);
	//The division of the operation to get the movement according to x and y
	const float dividingMovementFactor = sqrt(pow(destination.getCoordinate().x - position.x, 2) + pow(destination.getCoordinate().y - position.y, 2));
	//We fist calculate the x movement so we can check if the destination.getCoordinate() is reached
	const float movementX = (destination.getCoordinate().x - position.x) * deltaTime * speed / dividingMovementFactor;
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

void LifeForm::setDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	this->destination = destination;
	setRotatingDestination(destination);

	actionQueue.push(Action::Move);
}

void LifeForm::setRotatingDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	directionAngle = position.angle(destination.getCoordinate());

	clearAction();
	actionQueue.push(Action::Turn);
}

void LifeForm::checkCollision(const Map& map, Position<> position, short radius) {
	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {
			Position<> pointToCheck{ position.x + radius * i, position.y + radius * j };
			Position<> tilePosition{ map.getTile(pointToCheck).getPosition() };
			if (!map.getTile(pointToCheck).isWalkable()/* && position.rectIntersectCircle(tilePosition, Tile::tileSize, Tile::tileSize, radius)*/) {
				position.x = static_cast<float>(previousPosition.x);
				position.y = static_cast<float>(previousPosition.y);
				if (actionQueue.front() == Action::Move)
					actionQueue.pop();
				return;
			}
		}
	}
}

//The life form attack if it is facing the good direction
void LifeForm::attack(Position<> pointOfAttack) {
	if (inHandWeapon) {
		Angle angle = position.angle(Position<float>{static_cast<float>(pointOfAttack.x), static_cast<float>(pointOfAttack.y)});
		//If the target isn't in front of the life form
		if (angle.get() - deltaAngle > facingDirection.get() || angle.get() + deltaAngle < facingDirection.get()) {
			setRotatingDestination(pointOfAttack);
			actionQueue.push(Action::Attack);
		}
		else {
			inHandWeapon->attack(this);
		}
	}
}

bool LifeForm::isInSight(const Position<float>& entity) const {
	constexpr float PI = 3.14159265f;
	Angle angleEntityPlayer = facingDirection.difference(position.angle(entity));
	return (angleEntityPlayer.get() <= sightArea || angleEntityPlayer.get() >= 2 * PI - sightArea);
}

bool LifeForm::takeDamage(int amount) {
	healthPoint -= amount;
	return !isAlive();
}
