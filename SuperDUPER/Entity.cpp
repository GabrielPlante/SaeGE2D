#include "Entity.h"


Entity::Entity(double x, double y)
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer) {
	shape->setPosition(position.x, position.y);
	shape->render(renderer);
}

Entity::~Entity()
{
}
