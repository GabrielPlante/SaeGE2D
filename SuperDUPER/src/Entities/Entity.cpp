#include "../../header/Entities/Entity.h"


Entity::Entity(float x, float y, int healthPoint, int mass, float bluntDamageMultiplier, float sharpDamageMultiplier)
	: healthPoint{ healthPoint }, mass { mass }, bluntDamageMultiplier{ bluntDamageMultiplier }, sharpDamageMultiplier{ sharpDamageMultiplier }
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Camera& camera) const {
	shape->render(renderer, camera, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)});
}

void Entity::takeBluntDamage(int amount) {
	healthPoint -= static_cast<int>(amount*bluntDamageMultiplier);
}

void Entity::takeSharpDamage(int amount) {
	healthPoint -= static_cast<int>(amount*sharpDamageMultiplier);
}

Entity::~Entity()
{
}
