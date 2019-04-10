#pragma once
#include <SDL.h>
#include "Camera.h"
#include <list>
#include <memory>
class LifeForm;
class Map;
class WeaponAttack
{
public:
	WeaponAttack();
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	//Return true if the projectile doesn't exist anymore
	virtual bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) = 0;
	virtual std::unique_ptr<WeaponAttack> clone(Angle facingDirection, Position<float> position, int ownerId) const = 0;
	~WeaponAttack();
};

