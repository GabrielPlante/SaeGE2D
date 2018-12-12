#pragma once
#include "Entity.h"
#include <math.h>

class LifeForm :
	public Entity
{
public:
	LifeForm(double x, double y, int speed, int healthPoint, double facingDirection = 0, double rotatingSpeed = .1);
	bool refresh() override;
	bool move(const IntPosition& destination);
	void rotate(double directionAngle, double rotatingSpeed);
	void setDestination(int x, int y);
	~LifeForm();
private:
	int actualSpeed;
	int baseSpeed;
	double rotatingSpeed;
	int healthPoint;
	double directionAngle;
	double facingDirection;//The direction the lifeform currently face
	IntPosition destination;
	bool isMoving = false;
	Uint32 timeAtLastMovement;
};

