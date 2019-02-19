#pragma once
#include "MeleeWeapon.h"
class BasicSword :
	public MeleeWeapon
{
public:
	BasicSword();
	void render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const override;
	bool refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms, float deltaTime) override { return false; }
	~BasicSword();
};

