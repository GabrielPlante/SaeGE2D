#pragma once
#include "Projectile.h"
#include "Angle.h"
class BasicArrow :
	public Projectile
{
public:
	BasicArrow(Angle facingDirection, Position<float> position);
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	std::unique_ptr<Projectile> clone(Angle facingDirection, Position<float> position) const;
	~BasicArrow();
};

