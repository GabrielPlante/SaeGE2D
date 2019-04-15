#include "Projectile.h"
#include "LifeForm.h"



Projectile::Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<float> position, short speed,
	short range, float damageMultiplier, short mass, float sharpness, int ownerId)
	: Item{ name, encumbrance }, WeaponAttack{ range }, movement{ position, facingDirection }, speed{ speed },
	damageMultiplier{ damageMultiplier }, mass{ mass }, sharpness{ sharpness }, ownerId{ ownerId }
{
	startingPosition.x = static_cast<float>(position.x);
	startingPosition.y = static_cast<float>(position.y);
}

bool Projectile::refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) {
	//First calculate where the projectile will land
	movement.move(speed, deltaTime);
	//Check the range
	if (movement.getPosition().distanceSquared(startingPosition) > pow(getRange(), 2))
		return true;
	//check for everything
	for (auto it = lifeForms.begin(); it != lifeForms.end(); it++) {
		if ((**it).getId() != ownerId && (**it).pointIsOnThis(Position<>{static_cast<long>(movement.getPosition().x), static_cast<long>(movement.getPosition().y)})) {
			(**it).takeDamage(Damage{ getDamageMultiplier()*speed, mass, sharpness, 1, 0 });
			return true;
		}
	}
	return false;
}

Projectile::~Projectile()
{
}
