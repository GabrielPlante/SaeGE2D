#include "Map.h"

Map::Map()
{
	chunks[0].insert(std::make_pair(0, Chunk{ 0, 0 }));
	chunks[1].insert(std::make_pair(0, Chunk{ 1, 0 }));
}

void Map::render(SDL_Renderer* renderer, const Camera& camera) const {
	for (auto const& it : chunks) {
		for (auto const& id : it.second) {
			id.second.render(renderer, camera);
		}
	}
}

Map::~Map()
{
}
