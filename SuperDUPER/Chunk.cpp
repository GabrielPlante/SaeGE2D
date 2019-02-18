#include "Map.h"
#include "DefaultTile.h"


Map::Chunk::Chunk(int x, int y)
	: position{ x, y } {
	//Temporary, construct a chunk full of default tile
	//The delta of the position caused by the chunk position
	constexpr int tilePosChange = chunkSize * Tile::tileSize;
	for (int i = 0; i != chunkSize; i++) {
		for (int j = 0; j != chunkSize; j++) {
			tiles[i][j] = std::shared_ptr<Tile>(new DefaultTile{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
		}
	}
}

void Map::Chunk::render(SDL_Renderer* renderer, const Camera& camera) const {
	if (camera.isInCamera(Rectangle(position.x, position.y, chunkSize*Tile::tileSize, chunkSize*Tile::tileSize))) {
		for (auto it = tiles.begin(); it != tiles.end(); it++) {
			for (auto id = it->begin(); id != it->end(); id++) {
				(**id).render(renderer, camera);
			}
		}
	}
}