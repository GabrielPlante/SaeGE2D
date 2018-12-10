#include "Map.h"

Map::Map()
{
	chunks.emplace_back(0, 0);
}

void Map::render(SDL_Renderer* renderer, const Viewport& viewport) {
	int nbrOfChunk = chunks.size();
	if (nbrOfChunk) {
		Chunk* chunkPtr = &chunks[0];
		for (int i = 0; i != nbrOfChunk; i++) {
			chunkPtr[i].render(renderer, viewport);
		}
	}
}

Map::~Map()
{
}
