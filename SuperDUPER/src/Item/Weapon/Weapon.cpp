#include "../../../header/Item/Weapon/Weapon.h"
#include "../../../header/Entities/LifeForm.h"


Weapon::Weapon(const std::string& name, int mass, int damageMultiplier, int range, float fireRate, float sharpness, std::unique_ptr<WeaponAttack> weaponAttackType)
	:Item{ name, mass }, damageMultiplier{ damageMultiplier }, range{ range }, fireRate{ fireRate }, sharpness{ sharpness }, weaponAttackType{ std::move(weaponAttackType) }
{
}

void Weapon::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	for (auto it = weaponAttackList.begin(); it != weaponAttackList.end(); it++) {
		(**it).render(renderer, camera, owner);
	}
}

bool Weapon::refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime, const std::vector<float>& gameValues) {
	auto it = weaponAttackList.begin();
	while (it != weaponAttackList.end()) {
		if ((**it).refresh(map, lifeForms, deltaTime, gameValues))//Refresh the projectile and check if it's still alive
			it = weaponAttackList.erase(it);
		else
			it++;
	}
	return false;
}

bool Weapon::attack(LifeForm* owner) {
	auto deltaTime = clock.getTime();
	if (deltaTime < static_cast<long long>(fireRate * 1000 * 1000))
		return false;
	clock.resetTime();
	weaponAttackList.push_back(weaponAttackType->clone(owner->getFacingDirection(), owner->getPosition(), owner->getId()));
	return true;
}

int Weapon::getBluntDamage() const {
	return damageMultiplier * getMass();
}

int Weapon::getSharpDamage(const LifeForm& owner) const {
	return static_cast<int>(damageMultiplier * owner.getDamageMultiplier() * sharpness);
}


Weapon::~Weapon()
{
}
