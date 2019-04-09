#include "RangeWeapon.h"
#include "BasicArrow.h"
#include "LifeForm.h"


RangeWeapon::RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate, std::unique_ptr<Projectile> projectileType)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate, 0 }, projectileType{ std::move(projectileType) }
{
}

//Render all the projectiles
void RangeWeapon::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	for (auto it = projectiles.begin(); it != projectiles.end(); it++) {
		(**it).render(renderer, camera);
	}
}

bool RangeWeapon::refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) {
	auto it = projectiles.begin();
	while (it != projectiles.end()) {
		if ((**it).refresh(map, lifeForms, deltaTime))//Refresh the projectile and check if it's still alive
			it = projectiles.erase(it);
		else
			it++;
	}
	return false;
}

bool RangeWeapon::attack(LifeForm* lifeForm) {
	if (!Weapon::attack(lifeForm))
		return false;
	projectiles.push_back(projectileType->clone(lifeForm->getFacingDirection(), lifeForm->getPosition(), projectileType->getSpeed(), projectileType->getRange(), projectileType->getDamage(), lifeForm->getId()));
	return false;
}

RangeWeapon::~RangeWeapon()
{
}
