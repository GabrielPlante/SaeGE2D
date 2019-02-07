#include "MeleeWeapon.h"
#include "LifeForm.h"


MeleeWeapon::MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }
{
}

void MeleeWeapon::render(SDL_Renderer* renderer, const Camera& camer, const Position<double> playerPosition, const double facingDirection, const int playerRadius) const {
}

bool MeleeWeapon::attack(LifeForm* lifeForm) {
	if (!Weapon::attack(lifeForm))
		return false;
	lifeForm->takeDamage(getBaseDamage());
	return true;
}

MeleeWeapon::~MeleeWeapon()
{
}
