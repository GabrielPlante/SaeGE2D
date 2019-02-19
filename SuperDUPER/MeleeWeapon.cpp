#include "MeleeWeapon.h"
#include "LifeForm.h"


MeleeWeapon::MeleeWeapon(const std::string& name, int encumbrance, int baseDamage, int range, float fireRate)
	:Weapon{ name, encumbrance, baseDamage, range, fireRate }
{
}

bool MeleeWeapon::attack(LifeForm* owner) {
	if (!Weapon::attack(owner))
		return false;
	/*lifeForm->takeDamage(getBaseDamage());
	return true;
	**TODO Need to be changed to a slice in front of the owner and a check to everything it touch
	*/
}

MeleeWeapon::~MeleeWeapon()
{
}
