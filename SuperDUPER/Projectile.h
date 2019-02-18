#pragma once
#include <SDL.h>
#include "Camera.h"
#include "Angle.h"
class Projectile
{
public:
	Projectile(double speed, Angle facingDirection, int range, Position<double> position);
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	virtual bool refresh() = 0;//Return true if the projectile doesn't exist anymore
	const Position<double>& getPosition() const { return position; }
	Angle getFacingDirection() const { return facingDirection; }
	~Projectile();
private:
	double speed;
	Angle facingDirection;
	int range;
	Position<double> position;


};

