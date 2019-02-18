#include "BasicBow.h"



BasicBow::BasicBow()
	:RangeWeapon{ "Basic Bow", 100, 100, 1000, 0.5 }
{
}

bool BasicBow::attack(LifeForm* lifeForm) {
	return false;
}

BasicBow::~BasicBow()
{
}
