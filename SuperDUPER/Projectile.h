#pragma once
#include <SDL.h>
#include "Camera.h"
#include "Angle.h"
#include "WeaponAttack.h"
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
	public WeaponAttack, public Item
{
public:
	Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<float> position, unsigned short speed,
		unsigned short range, float damageMultiplier, unsigned short mass, float sharpness, int ownerId);
	//Information about the projectiles that doesn't change are not kept to avoid duplicate
	bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) override;//Return true if the projectile doesn't exist anymore
	~Projectile();
protected:
	const Position<float> getPosition() const { return movement.getPosition(); }
	unsigned short getSpeed() const { return speed; }
	unsigned short getBluntDamage() const { return static_cast<unsigned short>(damageMultiplier * mass * speed); }
	unsigned short getSharpDamage() const { return static_cast<unsigned short>(damageMultiplier * sharpness * speed); }
	unsigned short getMass() const { return mass; }
	float getDamageMultiplier() const { return damageMultiplier; }
	float getSharpness() const { return sharpness; }
	Angle getFacingDirection() const { return movement.getFacingDirection(); }
private:
	Movement movement;
	unsigned short speed;
	unsigned short mass;
	float damageMultiplier;
	float sharpness;
	Position<float> startingPosition;
	int ownerId;
};

