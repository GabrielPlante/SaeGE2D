#include "../../header/Map/Map.h"
#include "../../header/Map/DefaultTile.h"
#include "../../header/Map/BedRock.h"
#include "../../header/Map/ErrorTile.h"


Map::Chunk::Chunk(int x, int y)
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

 * Wrong number || 255 == ErrorTile
 */
Map::Chunk::Chunk(int x, int y, std::array<unsigned char, Map::chunkSize*Map::chunkSize> chunkMap) {
	constexpr int tilePosChange = chunkSize * Tile::tileSize;
	for (int i = 0; i != chunkSize; i++) {
		for (int j = 0; j != chunkSize; j++) {
			switch (chunkMap[i*chunkSize+j])
			{
			case 0:
				tiles[i][j] = std::shared_ptr<Tile>(new DefaultTile{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
				break;
			case 1:
				tiles[i][j] = std::shared_ptr<Tile>(new BedRock{ i*Tile::tileSize + x * tilePosChange, j*Tile::tileSize + y * tilePosChange });
				break;
			case 255:
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
