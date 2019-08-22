#include "Projectile.h"
#include "LifeForm.h"
#include "EntityList.h"



Projectile::Projectile(const std::string& name, int mass, Angle facingDirection, Position<float> position, int speed,
	int range, float damageMultiplier, float sharpness, unsigned long ownerId)
	: Item{ name, mass }, WeaponAttack{ range, damageMultiplier, sharpness }, movement{ position, facingDirection },
	speed{ speed }, ownerId{ ownerId }
{
	startingPosition.x = static_cast<float>(position.x);
	startingPosition.y = static_cast<float>(position.y);
}

bool Projectile::refresh(const Map& map, const EntityList& lifeForms, float deltaTime, const std::vector<float>& gameValues) {
	//First calculate where the projectile will land
	movement.move(speed, deltaTime);
	//Check the range
	if (movement.getPosition().distanceSquared(startingPosition) > pow(getRange(), 2))
		return true;
	//check for everything
	for (auto it = lifeForms.cbegin(); it != lifeForms.cend(); it++) {
		if ((**it).getId() != ownerId && (**it).pointIsOnThis(Position<>{static_cast<long>(movement.getPosition().x), static_cast<long>(movement.getPosition().y)})) {
			(**it).takeDamage(Damage{ damageMultiplier*speed, getMass(), sharpness, 1, 0 });
			return true;
		}
	}
	return false;
}

Projectile::~Projectile()
{
}
