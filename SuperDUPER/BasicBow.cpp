#include "BasicBow.h"



BasicBow::BasicBow(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms)
	:RangeWeapon{ "Basic Bow", 100, 100, 1000, 0.5, 1000, map, lifeForms }
{
}

void BasicBow::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	RangeWeapon::render(renderer, camera, owner);
}


bool BasicBow::refresh() {
	return RangeWeapon::refresh();
}

bool BasicBow::attack(LifeForm* lifeForm) {
	return false;
}

BasicBow::~BasicBow()
{
}
