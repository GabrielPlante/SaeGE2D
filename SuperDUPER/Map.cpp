#include "Map.h"
#include <iostream>

Map::Map()
{
	chunks[0].emplace_back(0, 0);
}

void Map::render(SDL_Renderer* renderer, const Camera& camera) const {
	for (auto it = chunks.begin(); it != chunks.end(); it++) {
		for (auto id = it->begin(); id != it->end(); id++) {
			id->render(renderer, camera);
		}
	}
}

Map::~Map()
{
}
