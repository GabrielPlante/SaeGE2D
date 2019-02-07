#include "RangeWeapon.h"



RangeWeapon::RangeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }
{
}

void RangeWeapon::render(SDL_Renderer* renderer, const Camera& camer, const Position<double> playerPositiona, const double facingDirection, const int playerRadius) const {

}

bool RangeWeapon::attack(LifeForm* lifeForm) {
	return false;
}

RangeWeapon::~RangeWeapon()
{
}
