#pragma once
#include "Entity.h"
#include <math.h>

class LifeForm :
	public Entity
{
public:
	LifeForm(double x, double y, int speed);
	bool refresh() override;
	void setDestination(int x, int y);
	~LifeForm();
private:
	int actualSpeed;
	int baseSpeed;
	SDL_Point destination;
	Uint32 timeAtLastMovement = 0;
};

