#pragma once
#include "Weapon.h"
class MeleeWeapon :
	public Weapon
{
public:
	MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate = 1);
	void render(SDL_Renderer* renderer, const Camera& camera, const Position<double> playerPosition, const double facingDirection, const int playerRadius) const override;
	bool attack(LifeForm* lifeForm) override;
	~MeleeWeapon();
private:
};

