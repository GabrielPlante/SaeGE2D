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
	WeaponAttack(unsigned short range);
	virtual void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const = 0;
	//Return true if the projectile doesn't exist anymore
	virtual bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) = 0;
	virtual std::unique_ptr<WeaponAttack> clone(Angle facingDirection, Position<float> position, int ownerId) const = 0;
	~WeaponAttack();
protected:
	unsigned short getRange() const { return range; }
private:
	unsigned short range;
};

