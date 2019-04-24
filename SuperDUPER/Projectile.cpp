#include "Projectile.h"
#include "LifeForm.h"



Projectile::Projectile(const std::string& name, short mass, Angle facingDirection, Position<float> position, short speed,
	short range, float damageMultiplier, float sharpness, int ownerId)
	: Item{ name, mass }, WeaponAttack{ range, damageMultiplier, sharpness }, movement{ position, facingDirection },
	speed{ speed }, ownerId{ ownerId }
{
	startingPosition.x = static_cast<float>(position.x);
	startingPosition.y = static_cast<float>(position.y);
}

bool Projectile::refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime) {
	//First calculate where the projectile will land
	movement.move(speed, deltaTime);
	//Check the range
	if (movement.getPosition().distanceSquared(startingPosition) > pow(getRange(), 2))
		return true;
	//check for everything
	/*for (auto it = lifeForms.getLifeFormList().begin(); it != lifeForms.getLifeFormList().end(); it++) {
		if ((**it).getId() != ownerId && (**it).pointIsOnThis(Position<>{static_cast<long>(movement.getPosition().x), static_cast<long>(movement.getPosition().y)})) {
			(**it).takeDamage(Damage{ damageMultiplier*speed, getMass(), sharpness, 1, 0 });
			return true;
		}
	}*/
	return false;
}

Projectile::~Projectile()
{
}
