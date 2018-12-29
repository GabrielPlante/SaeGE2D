#pragma once
#include "Entity.h"
#include <math.h>
#include "Destination.h"
#include <chrono>

class LifeForm :
	public Entity
{
public:
	LifeForm(double x, double y, int speed, int healthPoint, double facingDirection = 0, double rotatingSpeed = .1, int sightRange = 1000, float sightArea = 1);
	bool refresh() override;
	bool move(const Destination& destination, const int speed);
	void rotate(double directionAngle, double rotatingSpeed);
	void setDestination(const Destination destination);
	bool isInSight(const Position<double>& position) const;
	int getSightRange() const { return sightRange; }
	float getSightArea() const { return sightArea; }
	double getFacingDirection() const { return facingDirection; }
	~LifeForm();
private:
	const int id;
	static int idCount;//Each lifeForm has a unique ID
	int actualSpeed;
	int sightRange;
	float sightArea;
	int baseSpeed;//Speed unit is : pixel/sec
	double rotatingSpeed;
	int healthPoint;
	double directionAngle;//All angle are in radian, in [0-2PI]
	double facingDirection;//The direction the lifeform currently face
	Destination destination;
	bool isMoving = false;
	bool isTurning = false;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastMovement;
};

