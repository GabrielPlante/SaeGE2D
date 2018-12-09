#include "Map.h"

Map::Map()
{
}

void Map::render(SDL_Renderer* renderer) {
	int nbrOfChunk = chunks.size();
	if (nbrOfChunk) {
		Chunk* chunkPtr = &chunks[0];
		for (int i = 0; i != nbrOfChunk; i++) {
			chunkPtr[i].render(renderer);
		}
	}
}

Map::~Map()
{
}
