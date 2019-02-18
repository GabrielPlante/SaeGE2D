#pragma once
#include "RangeWeapon.h"
class BasicBow :
	public RangeWeapon
{
public:
	BasicBow(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms);
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const override;
	bool refresh() override;
	bool attack(LifeForm* lifeForm) override;
	~BasicBow();
};

