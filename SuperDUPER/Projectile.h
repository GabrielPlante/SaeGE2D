#pragma once
#include <SDL.h>
#include "Camera.h"
#include "Angle.h"
#include "Item.h"
#include <vector>
#include <memory>
#include <chrono>
#include "Movement.h"
#include <list>
class Map;
class LifeForm;
/*
 * Projectile is derived in different type of projectile (arrow-like, grenade-like...), each have to implement render and clone
*/
class Projectile :
	public Item
{
public:
	Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<float> position, unsigned short speed, unsigned short range, unsigned short damage, int ownerId);
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	//Information about the projectiles that doesn't change are not kept to avoid duplicate
	bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime);//Return true if the projectile doesn't exist anymore
	virtual std::unique_ptr<Projectile> clone(Angle facingDirection, Position<float> position, unsigned short speed, unsigned short range, unsigned short damage, int ownerId) const = 0;
	const Position<float> getPosition() const { return movement.getPosition(); }
	unsigned short getSpeed() const { return speed; }
	unsigned short getRange() const { return range; }
	unsigned short getDamage() const { return damage; }
	unsigned short getBluntDamage() const { return damage; }
	Angle getFacingDirection() const { return movement.getFacingDirection(); }
	~Projectile();
private:
	Movement movement;
	unsigned short speed;
	unsigned short range;
	unsigned short damage;
	Position<float> startingPosition;
	int ownerId;
};

