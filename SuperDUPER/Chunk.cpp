#include "Map.h"
#include "DefaultTile.h"
#include "BedRock.h"
#include "ErrorTile.h"


Map::Chunk::Chunk(short x, short y)
	: position{ x, y } {
	//Default constructor, make a chunk full of default tile
	//The delta of the position caused by the chunk position
	constexpr int tilePosChange = chunkSize * Tile::tileSize;
	for (int i = 0; i != chunkSize; i++) {
		for (int j = 0; j != chunkSize; j++) {
			tiles[i][j] = std::shared_ptr<Tile>(new DefaultTile{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
		}
	}
}

/*
 * Constructor with a map of what the chunk is composed of
 * 0 == Default tile
 * 1 == BedRock
 */
Map::Chunk::Chunk(short x, short y, std::array<unsigned char, Map::chunkSize*Map::chunkSize> chunkMap) {
	constexpr int tilePosChange = chunkSize * Tile::tileSize;
	for (int i = 0; i != chunkSize; i++) {
		for (int j = 0; j != chunkSize; j++) {
			switch (chunkMap[i*chunkSize+j])
			{
			case 0:
				tiles[i][j] = std::shared_ptr<Tile>(new DefaultTile{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
			case 1:
				tiles[i][j] = std::shared_ptr<Tile>(new BedRock{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
			default:
				tiles[i][j] = std::shared_ptr<Tile>(new ErrorTile{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
				break;
			}
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
