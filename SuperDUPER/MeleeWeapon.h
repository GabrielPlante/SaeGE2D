#pragma once
#include "Weapon.h"
class MeleeWeapon :
	public Weapon
{
public:
	MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate = 1);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	bool refresh() = 0;
	bool attack(LifeForm* lifeForm) override;
	~MeleeWeapon();
private:
};

