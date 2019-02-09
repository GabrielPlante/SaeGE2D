#include "MeleeWeapon.h"
#include "LifeForm.h"


MeleeWeapon::MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }
{
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
