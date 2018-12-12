#include "BedRock.h"


BedRock::BedRock(int x, int y)
	:Tile(x, y, Color(128, 128, 128))
{
}

bool BedRock::isDestructible() {
	return false;
}

bool BedRock::isWalkable() {
	return false;
}

BedRock::~BedRock()
{
}
