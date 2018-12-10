#include "Chunk.h"
#include "DefaultTile.h"


Chunk::Chunk(int x, int y)
	: position{ x, y } {
	//Temporary, construct a chunk full of default tile
	//The delta of the position caused by the chunk position
	constexpr int tilePosChange = chunkSize * Tile::tileSize;
	for (int i = 0; i != chunkSize; i++) {
		for (int j = 0; j != chunkSize; j++) {
			tiles[i*chunkSize + j] = std::shared_ptr<Tile>(new DefaultTile{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
		}
	}
	isInitialised = true;
}

void Chunk::render(SDL_Renderer* renderer, const Viewport& viewport) {
	if (isInitialised) {
		if (viewport.isInViewport(Rectangle(position.x, position.y, chunkSize*Tile::tileSize, chunkSize*Tile::tileSize))) {
			for (int i = 0; i != nbrOfTile; i++) {
				tiles[i]->render(renderer, viewport);
			}
		}
	}
}

Chunk::~Chunk()
{
}
