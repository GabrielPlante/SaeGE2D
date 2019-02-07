#pragma once
#include "Weapon.h"
class MeleeWeapon :
	public Weapon
{
public:
	MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate = 1);
	bool attack(LifeForm* lifeForm);
	~MeleeWeapon();
private:
};

