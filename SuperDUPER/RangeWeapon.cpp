#include "RangeWeapon.h"



RangeWeapon::RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }
{
}

bool RangeWeapon::refresh() {
	auto it = projectiles.begin();
	while (it != projectiles.end()) {
		if ((**it).refresh())//Refresh the projectile and check if it's still alive
			it = projectiles.erase(it);
		else
			it++;
	}
	return false;
}

bool RangeWeapon::attack(LifeForm* lifeForm) {
	return false;
}

RangeWeapon::~RangeWeapon()
{
}
