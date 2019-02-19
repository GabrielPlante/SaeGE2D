#include "Projectile.h"
#include "LifeForm.h"



Projectile::Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<double> position)
	: Item{ name, encumbrance }, facingDirection{ facingDirection }, position{ position }
{
}

bool Projectile::refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms, float speed, int range,
	long long deltaTime, int damage) {
	//First calculate where the projectile will land
	const double multiplyingFactor = speed * deltaTime / (1000 * 1000);
	const double x = cos(facingDirection.get())*multiplyingFactor + position.x;
	const double y = sin(facingDirection.get())*multiplyingFactor + position.y;
	//check for everything
	for (auto it = lifeForms.begin(); it != lifeForms.end(); it++) {
		if (position.lineIntersectWithCircle(Position<>(x, y), Position<>(static_cast<long>((**it).getPosition().x), static_cast<long>((**it).getPosition().y))
			, (**it).getRadius())) {
			(**it).takeDamage(damage);
			return true;
		}
	}
	position.x = x;
	position.y = y;
	return false;
}

Projectile::~Projectile()
{
}
