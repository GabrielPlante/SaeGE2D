#pragma once
#include "Projectile.h"
#include "Angle.h"
class BasicArrow :
	public Projectile
{
public:
	BasicArrow(Angle facingDirection, Position<float> position, unsigned short speed,
		unsigned short range, float damageMultiplier, unsigned short mass, float sharpness, int ownerId);
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	std::unique_ptr<WeaponAttack> clone(Angle facingDirection, Position<float> position, int ownerId) const override;
	~BasicArrow();
};

