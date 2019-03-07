#pragma once
#include "Projectile.h"
#include "Angle.h"
class BasicArrow :
	public Projectile
{
public:
	BasicArrow(Angle facingDirection, Position<float> position, unsigned short speed, unsigned short range, unsigned short damage, int ownerId);
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	std::unique_ptr<Projectile> clone(Angle facingDirection, Position<float> position, unsigned short speed, unsigned short range, unsigned short damage, int ownerId) const override;
	~BasicArrow();
};

