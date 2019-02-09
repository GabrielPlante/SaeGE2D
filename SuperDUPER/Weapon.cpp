#include "Weapon.h"



Weapon::Weapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Item{ name, encumbrance }, baseDamage{ baseDamage }, range{ range }, fireRate{ fireRate }
{
}

bool Weapon::attack(LifeForm* lifeForm) {
	const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastHit).count() };
	if (deltaTime < static_cast<long long>(fireRate * 1000 * 1000))
		return false;
	timeAtLastHit = std::chrono::high_resolution_clock::now();
	return true;
}

Weapon::~Weapon()
{
}
