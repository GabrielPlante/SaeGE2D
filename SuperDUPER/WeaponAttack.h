#pragma once
#include <SDL.h>
#include "Camera.h"
#include <list>
#include <memory>
class LifeForm;
class Map;
class LifeFormList;
class WeaponAttack
{
public:
	WeaponAttack(short range, float damageMultiplier, float sharpness);
	virtual void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	//Return true if the projectile doesn't exist anymore
	virtual bool refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime) = 0;
	virtual std::unique_ptr<WeaponAttack> clone(Angle facingDirection, Position<float> position, int ownerId) const = 0;
	~WeaponAttack();
protected:
	short getRange() const { return range; }
	float damageMultiplier;
	float sharpness;
private:
	short range;
};

