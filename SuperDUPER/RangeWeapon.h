#pragma once
#include "Weapon.h"
#include "Projectile.h"
#include <list>
class RangeWeapon :
	public Weapon
{
public:
	RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate = 1);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	bool refresh() = 0;
	bool attack(LifeForm* lifeForm) override;
	~RangeWeapon();
private:
	std::list<std::unique_ptr<Projectile>> projectiles;
};

