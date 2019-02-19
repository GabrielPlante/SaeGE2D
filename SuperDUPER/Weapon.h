#pragma once
#include <chrono>
#include "Item.h"
#include <SDL.h>
#include "Camera.h"
#include "Position.h"
#include <vector>
class Map;
class LifeForm;
class Weapon :
	public Item
{
public:
	Weapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate);
	virtual void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	virtual bool refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms) = 0;
	virtual bool attack(LifeForm* owner) = 0;//Return true if the attack occur
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

