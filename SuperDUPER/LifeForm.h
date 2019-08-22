#pragma once
#include "Sight.h"
#include "Entity.h"
#include <math.h>
#include "AdvancedMovement.h"
#include "StatusEffect.h"
#include <chrono>
#include <vector>
#include <queue>
#include "Weapon.h"
#include "Attributes.h"

enum class Friendliness {Neutral, Friend, Enemy};

enum class Action { Move, Turn, Attack };

class LifeForm :
	public Entity
{
public:
	//---Internal processing---
	LifeForm(float x, float y, int speed, int healthPoint, int radius, int mass = 0, Friendliness friendliness = Friendliness::Neutral,
		float facingDirection = 0, float rotatingSpeed = .1, int sightRange = 1000, float sightArea = 1, Attributes attributes = Attributes{});//The default constructor
	void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	bool refresh(const Map& map, const EntityList& lifeForms, float deltaTime, const std::vector<float>& gameValues) override;//Method to call each frame, return false if the player is still alive (return !isAlive())
	//Return true if the destination is reached
	void setRotatingDestination(const Destination& destination);
	void checkCollision(const Map& map, Position<> position, int radius);

	//---External information---
	bool isInSight(const Position<float>& otherPos) const override { return sight.isInSight(position, otherPos, facingDirection); }
	int getDamageMultiplier() const { return strength; }
	int getHealthPoint() const { return healthPoint; }
	int getSightRange() const { return sight.getSightRange(); }
	float getSightArea() const { return sight.getSightArea(); }
	Angle getFacingDirection() const { return facingDirection; }
	Friendliness getFriendliness() const { return friendliness; }
	int getRadius() const { return radius; }
	bool isAlive() const { return healthPoint > 0; }

	//---External order---
	void setDestination(const Destination& destination);
	void attack(Position<> pointOfAttack);
	bool takeDamage(const Damage& damage) override;//Return true if the lifeform is alive 
	void takeWeaponInHand(std::unique_ptr<Weapon> weapon) { inHandWeapon = std::move(weapon); }
	void clearDestination() { movement.setDestination(Destination(this)); }
	void clearAction() { actionQueue = std::queue<Action>(); }
	void setVisionRendering(bool set) { renderVision = set; }
	void setHealthRendering(bool set) { renderHealth = set; }
private:
	Attributes attributes;
	int actualSpeed;//Speed unit is : pixel/sec
	int strength = 50;
	Sight sight;
	int baseSpeed;//Speed unit is : pixel/sec
	float rotatingSpeed;
	int baseHealtPoint = healthPoint;
	//All angle are in radian, in [0-2PI]
	Angle directionAngle;//The direction the lifeform want to turn to
	Angle facingDirection;//The direction the lifeform currently face
	AdvancedMovement movement = AdvancedMovement{ Destination{this} };
	std::unique_ptr<Weapon> inHandWeapon;//Item 
	int maxEncumbrance;
	Friendliness friendliness;
	std::queue<Action> actionQueue;
	std::vector<StatusEffect> statusEffectList;
	Position<float> previousPosition;
	bool renderVision = false;
	bool renderHealth = true;
protected:
	int radius;
};

