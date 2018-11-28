#include "Entity.h"



Entity::Entity(double x, double y)
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer) {
	shape->setPosition(static_cast<int>(position.x), static_cast<int>(position.y));
	shape->render(renderer);
}

Entity::~Entity()
{
}
