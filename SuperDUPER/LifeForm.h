#pragma once
#include "Entity.h"
#include <math.h>

class LifeForm :
	public Entity
{
public:
	LifeForm(double x, double y, int speed, int healthPoint);
	bool refresh() override;
	bool move(const SDL_Point& destination);
	void setDestination(int x, int y);
	~LifeForm();
private:
	int actualSpeed;
	int baseSpeed;
	int healthPoint;
	SDL_Point destination;
	bool isMoving = false;
	Uint32 timeAtLastMovement;
};

