#include "RangeWeapon.h"



RangeWeapon::RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }
{
}

//Render all the projectiles
void RangeWeapon::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	for (auto it = projectiles.begin(); it != projectiles.end(); it++) {
		(**it).render(renderer, camera);
	}
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
