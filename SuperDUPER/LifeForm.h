#pragma once
#include "Damage.h"
#include "Entity.h"
#include <math.h>
#include "AdvancedMovement.h"
#include "StatusEffect.h"
#include <chrono>
#include <vector>
#include <queue>
#include "Weapon.h"

enum class Friendliness {Neutral, Friend, Enemy};

enum class Action { Move, Turn, Attack };

class LifeForm :
	public Entity
{
public:
	//---Internal processing---
	LifeForm(float x, float y, int speed, short healthPoint, short radius, short mass = 0, Friendliness friendliness = Friendliness::Neutral,
		float facingDirection = 0, float rotatingSpeed = .1, int sightRange = 1000, float sightArea = 1);//The default constructor
	void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	bool refresh(const Map& map, const std::list<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) override;//Method to call each frame, return false if the player is still alive (return !isAlive())
	//Return true if the destination is reached
	void setRotatingDestination(const Destination& destination);
	void checkCollision(const Map& map, Position<> position, short radius);

	//---External information---
	bool isInSight(const Position<float>& position) const;//return true if a position is in sight
	short getDamageMultiplier() const { return strength; }
	int getHealthPoint() const { return healthPoint; }
	int getSightRange() const { return sightRange; }
	float getSightArea() const { return sightArea; }
	Angle getFacingDirection() const { return facingDirection; }
	Friendliness getFriendliness() const { return friendliness; }
	int getRadius() const { return radius; }
	bool isAlive() const { return healthPoint > 0; }
	int getId() const { return id; }
	bool operator==(const LifeForm& other) const { return id == other.getId(); }
	bool operator!=(const LifeForm& other) const { return id != other.getId(); }

	//---External order---
	void setDestination(const Destination& destination);
	void attack(Position<> pointOfAttack);
	bool takeDamage(const Damage& damage);//Return true if the lifeform is alive 
	void takeWeaponInHand(std::unique_ptr<Weapon> weapon) { inHandWeapon = std::move(weapon); }
	void clearDestination() { movement.setDestination(Destination(this)); }
	void clearAction() { actionQueue = std::queue<Action>(); }
	//---Getter of pointer for command purpose (might be changed latter)---
	int* getActualSpeedPtr() { return &actualSpeed; }
	float* getRotatingSpeedPtr() { return &rotatingSpeed; }
	short* getHealtPointPtr() { return &healthPoint; }
	float* getPositionXPtr() { return &position.x; }
	float* getPositionYPtr() { return &position.y; }
private:
	const int id;
	static int idCount;//Each lifeForm has a unique ID
	int actualSpeed;//Speed unit is : pixel/sec
	short strength = 50;
	int sightRange;
	float sightArea;//Between 0 (don't see anything) and PI (see everything)
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
protected:
	short radius;
};

