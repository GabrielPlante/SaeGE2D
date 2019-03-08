#pragma once
#include "Weapon.h"
#include "Projectile.h"
#include <vector>
#include <memory>

/*
 * The RangeWeapon class is the class that instantiate all the range weapon object.
 * It should not be derived, and to create different range weapon with different properties, the projectile shall change change.
*/
class RangeWeapon :
	public Weapon
{
public://TODO unduplicate range and damage information
	RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate, std::unique_ptr<Projectile> projectileType);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const;
	bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float);
	bool attack(LifeForm* lifeForm) override;
	~RangeWeapon();
private:
	std::list<std::unique_ptr<Projectile>> projectiles;
	//This projectile is used as a model and is cloned each time the player fire
	std::unique_ptr<Projectile> projectileType;
};

