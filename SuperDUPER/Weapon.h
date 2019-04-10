#pragma once
#include <chrono>
#include "Item.h"
#include <SDL.h>
#include "Camera.h"
#include "Position.h"
#include "WeaponAttack.h"
#include "Item.h"
#include <vector>
#include <list>
class Map;
class LifeForm;
class Weapon :
	public Item
{
public:
	Weapon(const std::string& name, short mass, int damageMultiplier, int range, float fireRate, float sharpness, std::unique_ptr<WeaponAttack> weaponAttackType);
	virtual void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const;
	//Return true if the weapon doesn't exist anymore
	bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime);
	bool attack(LifeForm* owner);//Return true if the attack occur
	int getDamageMultiplier() const { return damageMultiplier; }
	short getBluntDamage() const;
	short getSharpDamage(const LifeForm& owner) const;
	float getFireRate() const { return fireRate; }
	int getRange() const { return range; }
	~Weapon();
private:
	std::list<std::unique_ptr<WeaponAttack>> weaponAttackList;
	std::unique_ptr<WeaponAttack> weaponAttackType;
	int damageMultiplier;
	int range;
	float fireRate;
	float sharpness;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastHit;
};

