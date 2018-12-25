#include "Entity.h"
#include "Map.h"


Entity::Entity(double x, double y)
{
	position.x = x;
	position.y = y;
}

void Entity::render(SDL_Renderer* renderer, const Camera& viewport) {
	shape->setPosition(static_cast<int>(position.x), static_cast<int>(position.y));
	shape->render(renderer, viewport);
}

/*Position<> Entity::chunkPosition() const {
	return Position<>{
		static_cast<int>(position.x) / (Map::chunkSize*Tile::tileSize),
		static_cast<int>(position.y) / (Map::chunkSize*Tile::tileSize)
	};
}*/

Position<double> Entity::getPosition() const {
	return position;
}

bool Entity::pointIsOnThis(Position<> point) const {
	return shape->pointIsIn(point);
}

Entity::~Entity()
{
}
