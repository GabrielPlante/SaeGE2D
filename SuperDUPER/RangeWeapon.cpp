#include "RangeWeapon.h"


RangeWeapon::RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate, float projectileSpeed)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }, projectileSpeed{ projectileSpeed }
{
	timeAtLastFrame = std::chrono::high_resolution_clock::now();
}

//Render all the projectiles
void RangeWeapon::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	for (auto it = projectiles.begin(); it != projectiles.end(); it++) {
		(**it).render(renderer, camera);
	}
}

bool RangeWeapon::refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms) {
	long long deltaTime;
	if (!projectiles.empty())
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastFrame).count();
	timeAtLastFrame = std::chrono::high_resolution_clock::now();
	auto it = projectiles.begin();
	while (it != projectiles.end()) {
		if ((**it).refresh(map, lifeForms, projectileSpeed, getRange(), deltaTime, getBaseDamage()))//Refresh the projectile and check if it's still alive
			it = projectiles.erase(it);
		else
			it++;
	}
	return false;
}

RangeWeapon::~RangeWeapon()
{
}
