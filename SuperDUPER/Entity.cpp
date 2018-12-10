#include "Entity.h"
#include "Chunk.h"


Entity::Entity(double x, double y)
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Viewport& viewport) {
	shape->setPosition(static_cast<int>(position.x), static_cast<int>(position.y));
	shape->render(renderer, viewport);
}

IntPosition Entity::chunkPosition() const {
	return IntPosition{
		static_cast<int>(position.x) / (Chunk::chunkSize*Tile::tileSize),
		static_cast<int>(position.y) / (Chunk::chunkSize*Tile::tileSize)
	};
}

Entity::~Entity()
{
}
