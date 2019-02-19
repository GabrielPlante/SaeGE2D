#pragma once
#include "Weapon.h"
#include "Projectile.h"
#include <list>
#include <vector>
#include <memory>
class Map;
class RangeWeapon :
	public Weapon
{
public:
	RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate, float projectileSpeed, const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	bool refresh();
	~RangeWeapon();
private:
	float projectileSpeed;
	const Map& map;
	const std::vector<std::unique_ptr<LifeForm>>& lifeForms;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastFrame;
protected:
	std::list<std::unique_ptr<Projectile>> projectiles;
};

