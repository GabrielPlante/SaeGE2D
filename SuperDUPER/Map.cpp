#include "Map.h"

Map::Map()
{
}

void Map::render(SDL_Renderer* renderer) {
	int nbrOfTile = tiles.size();
	if (nbrOfTile) {
		Tile* tilePtr = &tiles[0];
		for (int i = 0; i != nbrOfTile; i++) {
			tilePtr[i].render(renderer);
		}
	}
}

Map::~Map()
{
}
