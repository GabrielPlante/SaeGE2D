#include "Projectile.h"



Projectile::Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<double> position)
	: Item{ name, encumbrance }, facingDirection{ facingDirection }, position{ position }
{
}


Projectile::~Projectile()
{
}
