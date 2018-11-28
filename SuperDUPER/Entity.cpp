#include "Entity.h"



Entity::Entity()
{
}

void Entity::render(SDL_Renderer* renderer) {
	shape->render(renderer);
}

Entity::~Entity()
{
}
