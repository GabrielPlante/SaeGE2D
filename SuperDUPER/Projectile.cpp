#include "Projectile.h"



Projectile::Projectile(double speed, Angle facingDirection, int range, Position<double> position)
	:speed{ speed }, facingDirection{ facingDirection }, range{ range }, position{ position }
{
}


Projectile::~Projectile()
{
}
