#include "Entity.h"
#include "Map.h"


Entity::Entity(float x, float y, short healthPoint, short mass, float bluntDamageMultiplier, float sharpDamageMultiplier)
	: healthPoint{ healthPoint }, mass { mass }, bluntDamageMultiplier{ bluntDamageMultiplier }, sharpDamageMultiplier{ sharpDamageMultiplier }
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Camera& camera) const {
	shape->render(renderer, camera, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)});
}

void Entity::takeBluntDamage(short amount) {
	healthPoint -= static_cast<short>(amount*bluntDamageMultiplier);
}

void Entity::takeSharpDamage(short amount) {
	healthPoint -= static_cast<short>(amount*sharpDamageMultiplier);
}

Entity::~Entity()
{
}
