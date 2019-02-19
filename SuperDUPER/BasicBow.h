#pragma once
#include "RangeWeapon.h"
class BasicBow :
	public RangeWeapon
{
public:
	BasicBow();
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const override;
	bool attack(LifeForm* lifeForm) override;
	~BasicBow();
};

