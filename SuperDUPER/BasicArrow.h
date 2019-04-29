#pragma once
#include "Projectile.h"
#include "Angle.h"
class BasicArrow :
	public Projectile
{
public:
	BasicArrow(Angle facingDirection, int mass, Position<float> position, int speed,
		int range, float damageMultiplier, float sharpness, int ownerId);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const;
	std::unique_ptr<WeaponAttack> clone(Angle facingDirection, Position<float> position, int ownerId) const override;
	~BasicArrow();
};

