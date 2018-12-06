#include "DefaultTile.h"



DefaultTile::DefaultTile(int x, int y)
	:Tile(x, y, Color(0, 0, 0))
{
}

bool DefaultTile::isWalkable() {
	return true;
}

bool DefaultTile::isDestructible() {
	return false;
}

DefaultTile::~DefaultTile()
{
}
