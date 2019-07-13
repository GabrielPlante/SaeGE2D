#pragma once
#include "Projectile.h"
#include "../../Struct/Angle.h"
class BasicArrow :
	public Projectile
{
public:
	BasicArrow(Angle facingDirection, int mass, Position<float> position, int speed,
		int range, float damageMultiplier, float sharpness, unsigned long ownerId);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const;
	std::unique_ptr<WeaponAttack> clone(Angle facingDirection, Position<float> position, unsigned long ownerId) const override;
	~BasicArrow();
};

