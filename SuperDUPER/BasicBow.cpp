#include "BasicBow.h"
#include "LifeForm.h"
#include "BasicArrow.h"



BasicBow::BasicBow()
	:RangeWeapon{ "Basic Bow", 100, 100, 1000, 0.5, 300 }
{
}

void BasicBow::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	RangeWeapon::render(renderer, camera, owner);
}

bool BasicBow::attack(LifeForm* lifeForm) {
	if (!Weapon::attack(lifeForm))
		return false;
	std::unique_ptr<Projectile> arrow{ new BasicArrow(lifeForm->getFacingDirection(), lifeForm->getPosition()) };
	projectiles.push_back(std::move(arrow));
	return false;
}

BasicBow::~BasicBow()
{
}
