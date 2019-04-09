#include "Weapon.h"
#include "LifeForm.h"


Weapon::Weapon(const std::string& name, short mass, int damageMultiplier, int range, float fireRate, float sharpness)
	:Item{ name, mass }, damageMultiplier{ damageMultiplier }, range{ range }, fireRate{ fireRate }, sharpness{ sharpness }
{
}

bool Weapon::attack(LifeForm* owner) {
	const long long deltaTime{ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastHit).count() };
	if (deltaTime < static_cast<long long>(fireRate * 1000 * 1000))
		return false;
	timeAtLastHit = std::chrono::high_resolution_clock::now();
	return true;
}

short Weapon::getBluntDamage() const {
	return damageMultiplier * getMass();
}

short Weapon::getSharpDamage(const LifeForm& owner) const {
	return static_cast<short>(damageMultiplier * owner.getStrength() * sharpness);
}


Weapon::~Weapon()
{
}
