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
	Projectile(const std::string& name, int mass, Angle facingDirection, Position<float> position, int speed,
		int range, float damageMultiplier, float sharpness, unsigned long ownerId);
	//Information about the projectiles that doesn't change are not kept to avoid duplicate
	bool refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime) override;//Return true if the projectile doesn't exist anymore
	~Projectile();
protected:
	const Position<float> getPosition() const { return movement.getPosition(); }
	int getSpeed() const { return speed; }
	int getBluntDamage() const { return static_cast<int>(damageMultiplier * getMass() * speed); }
	int getSharpDamage() const { return static_cast<int>(damageMultiplier * sharpness * speed); }
	Angle getFacingDirection() const { return movement.getFacingDirection(); }
private:
	Movement movement;
	int speed;
	Position<float> startingPosition;
	unsigned long ownerId;
};

