#include "LifeForm.h"
#include "Map.h"

constexpr float deltaAngle = 0.001f;

unsigned long LifeForm::idCount = 0;

LifeForm::LifeForm(float x, float y, int speed, int healthPoint, int radius, int mass, Friendliness friendliness,
	float directionAngle, float rotatingSpeed, int sightRange, float sightArea, Attributes attributes)
	:Entity(x, y, healthPoint, mass), baseSpeed{ speed }, actualSpeed{ speed }, radius{ radius }, friendliness{ friendliness },
	facingDirection{ directionAngle }, rotatingSpeed{ rotatingSpeed }, sight{ sightRange, sightArea },
	id{ idCount }, previousPosition{ x, y }, attributes{ attributes }
{
	idCount++;
}

void LifeForm::render(SDL_Renderer* renderer, const Camera& camera) const {
	Entity::render(renderer, camera);
	constexpr int halfLenght{ 40 };
	constexpr int height{ 30 };

	//healtbar (temporary)
	if (renderHealth) {
		SDL_SetRenderDrawColor(renderer, 230, 0, 0, 200);
		Position<> relativePosition{ camera.absoluteToRelative(static_cast<long>(position.x), static_cast<long>(position.y)) };
		for (int width = 0; width < 3; width++) {
			SDL_RenderDrawLine(renderer, relativePosition.x - halfLenght, relativePosition.y - height + width,
				relativePosition.x + static_cast<int>(halfLenght * (healthPoint * 2.0 / baseHealtPoint - 1)), relativePosition.y - height + width);
		}
	}
	if (renderVision) {
		Position<> relPlayerPosition{ camera.absoluteToRelative(static_cast<int>(position.x), static_cast<int>(position.y)) };
		Position<> line1{ camera.absoluteToRelative(static_cast<long int>(position.x + sight.getSightRange() * cos(facingDirection.get() + sight.getSightArea())),
			static_cast<long int>(position.y + sight.getSightRange() * sin(facingDirection.get() + sight.getSightArea()))) };
		Position<> line2{ camera.absoluteToRelative(static_cast<long int>(position.x + sight.getSightRange() * cos(facingDirection.get() - sight.getSightArea())),
			static_cast<long int>(position.y + sight.getSightRange() * sin(facingDirection.get() - sight.getSightArea()))) };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawLine(renderer, relPlayerPosition.x, relPlayerPosition.y, line1.x, line1.y);
		SDL_RenderDrawLine(renderer, relPlayerPosition.x, relPlayerPosition.y, line2.x, line2.y);
	}

	//Render the weapon
	if (inHandWeapon)
		inHandWeapon->render(renderer, camera, *this);
}

bool LifeForm::refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime, const std::vector<float>& gameValues) {
	//First all the status effects are applied
	for (auto it = statusEffectList.begin(); it != statusEffectList.end();) {
		if (it->refresh(this, deltaTime))
			it = statusEffectList.erase(it);
		else
			it++;
	}

	//Then the tile effect is applied
	map.getTile(Position<>{static_cast<long>(position.x), static_cast<long>(position.y)}).effectOnLifeForm(this);

	if (inHandWeapon)
		inHandWeapon->refresh(map, lifeForms, deltaTime, gameValues);

	if (actionQueue.empty());
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
		Angle angle = position.angle(movement.getDestination().getCoordinate());
		if (angle.get() < facingDirection.get() - deltaAngle && angle.get() > facingDirection.get() + deltaAngle)
			facingDirection = angle;
		previousPosition.x = position.x;
		previousPosition.y = position.y;
		if (movement.move(&position, actualSpeed, deltaTime))
			actionQueue.pop();
		checkCollision(map, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)}, radius);
	}

	return !isAlive();
}

void LifeForm::setDestination(const Destination& destination) {
	if (position == destination.getCoordinate())
		return;
	movement.setDestination(destination);
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

//Method to check collision, /!\ Only work if the player is smaller than a tile
void LifeForm::checkCollision(const Map& map, Position<> position, int radius) {
	//Check the "four corners" of the circle
	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {
			Position<> pointToCheck{ position.x + radius * i, position.y + radius * j };
			Position<> tilePosition{ map.getTile(pointToCheck).getPosition() };
			//Check if tile under the corner is walkable and if so check if the tile actually intersect the circle
			if (!map.getTile(pointToCheck).isWalkable() && position.rectIntersectCircle(
				//Adapt the tile position : original in the upper left corner, wanted in the middle of the tile
				Position<>{ tilePosition.x, tilePosition.y }, Tile::tileSize, Tile::tileSize, radius)) {

				this->position.x = previousPosition.x;
				this->position.y = previousPosition.y;
				if (!actionQueue.empty() && actionQueue.front() == Action::Move)
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
			clearAction();
			inHandWeapon->attack(this);
		}
	}
}

bool LifeForm::takeDamage(const Damage& damage) {
	healthPoint -= damage.getDamage(bluntDamageMultiplier, sharpDamageMultiplier);
	return !isAlive();
}
