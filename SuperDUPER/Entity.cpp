#include "Entity.h"
#include "Map.h"


Entity::Entity(double x, double y)
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Camera& camera) const {
	shape->setPosition(static_cast<int>(position.x), static_cast<int>(position.y));
	shape->render(renderer, camera);
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
