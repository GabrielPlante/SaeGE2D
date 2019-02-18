#pragma once
#include "Entity.h"
#include <math.h>
#include "Destination.h"
#include "Weapon.h"
#include <chrono>
#include <vector>

enum class Friendliness {Neutral, Friend, Enemy};

class LifeForm :
	public Entity
{
public:
	LifeForm(double x, double y, int speed, int healthPoint, int radius, Friendliness friendliness = Friendliness::Neutral,
		double facingDirection = 0, double rotatingSpeed = .1, int sightRange = 1000, float sightArea = 1);//The default constructor
	void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	bool refresh() override;//Method to call each frame
	//void move(const Destination& destination, const int speed);//Move toward a direction at a certain speed, instantaneous, call setDestination to have a repercution
	//void rotate(double directionAngle, double rotatingSpeed);//Same as move but for the rotation
	bool rawMovement(const Destination& destination, const int speed, const long long deltaTime);//Raw mean that the method doesn't change any boolean attribute
	bool rawRotation(Angle directionAngle, double rotatingSpeed, const long long deltaTime);
	void setDestination(const Destination& destination);
	void setRotatingDestination(const Destination& destination);
	void attack(LifeForm* lifeForm);
	bool isInSight(const Position<double>& position) const;//return true if a position is in sight
	int getHealthPoint() const { return healthPoint; }
	int getSightRange() const { return sightRange; }
	float getSightArea() const { return sightArea; }
	Angle getFacingDirection() const { return facingDirection; }
	Friendliness getFriendliness() const { return friendliness; }
	int getRadius() const { return radius; }
	bool takeDamage(int amount);//Return true if the lifeform is alive 
	bool isAlive() const { return healthPoint > 0; }
	void takeWeaponInHand(std::unique_ptr<Weapon> weapon) { inHandWeapon = std::move(weapon); }
	void clearDestination() { destination = Destination(this); }
	~LifeForm();
private:
	const int id;
	static int idCount;//Each lifeForm has a unique ID
	int actualSpeed;
	int sightRange;//Between 0 (don't see anything) and PI (see everything)
	float sightArea;
	int baseSpeed;//Speed unit is : pixel/sec
	double rotatingSpeed;
	int healthPoint;
	int baseHealtPoint = healthPoint;
	//All angle are in radian, in [0-2PI]
	Angle directionAngle;//The direction the lifeform want to turn to
	Angle facingDirection;//The direction the lifeform currently face
	Destination destination = Destination(this);
	bool isTurning = false;
	bool isAttacking = false;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastMovement;
	//std::vector<std::unique_ptr<Item>> backpack;
	std::unique_ptr<Weapon> inHandWeapon;//Item 
	int maxEncumbrance;
	Friendliness friendliness;
protected:
	int radius;
};

