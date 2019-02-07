#pragma once
#include <chrono>
#include "Item.h"
class LifeForm;
class Weapon :
	public Item
{
public:
	Weapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate);
	virtual bool attack(LifeForm* lifeForm) = 0;//Return true if the attack occur
	int getBaseDamage() const { return baseDamage; }
	float getFireRate() const { return fireRate; }
	int getRange() const { return range; }
	~Weapon();
private:
	int baseDamage;
	int range;
	float fireRate;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastHit;
};

