#include "Entity.h"
#include "Map.h"


Entity::Entity(float x, float y, short mass)
	:mass{ mass }
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Camera& camera) const {
	shape->render(renderer, camera, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)});
}

/*Position<> Entity::chunkPosition() const {
	return Position<>{
		static_cast<int>(position.x) / (Map::chunkSize*Tile::tileSize),
		static_cast<int>(position.y) / (Map::chunkSize*Tile::tileSize)
	};
}*/

Entity::~Entity()
{
}
