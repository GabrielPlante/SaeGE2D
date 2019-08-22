#include "Entity.h"

unsigned long Entity::idCount = 0;

Entity::Entity(float x, float y, int healthPoint, int mass, float bluntDamageMultiplier, float sharpDamageMultiplier)
	: healthPoint{ healthPoint }, mass { mass }, bluntDamageMultiplier{ bluntDamageMultiplier }, sharpDamageMultiplier{ sharpDamageMultiplier },
	id{ idCount }
{
	idCount++;
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Camera& camera) const {
	shape->render(renderer, camera, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)});
}
