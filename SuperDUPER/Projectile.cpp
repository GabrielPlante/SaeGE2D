#include "Projectile.h"
#include "LifeForm.h"



Projectile::Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<float> position)
	: Item{ name, encumbrance }, movement{ position, facingDirection }
{
	startingPosition.x = static_cast<float>(position.x);
	startingPosition.y = static_cast<float>(position.y);
}

bool Projectile::refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms, float speed, int range,
	float deltaTime, int damage) {
	//First calculate where the projectile will land
	movement.move(speed, deltaTime);
	//check for everything
	for (auto it = lifeForms.begin(); it != lifeForms.end(); it++) {
		if ((**it).pointIsOnThis(Position<>{static_cast<long>(movement.getPosition().x), static_cast<long>(movement.getPosition().y)})) {
			(**it).takeDamage(damage);
			return true;
		}
	}
	//Check the range
	if (movement.getPosition().distanceSquared(startingPosition) > pow(range, 2))
		return true;
	return false;
}

Projectile::~Projectile()
{
}
