#pragma once
#include "Camera.h"
#include <vector>
#include <memory>
#include <array>
#include <map>
#include "Tile.h"

class Map
{
public:
	Map();
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	constexpr static int chunkSize{ 20 };//Number of tile per line in the chunk
	const Tile& getTile(const Position<>& tilePosition) const {//Position in absolute in pixel
		Position<short> chunkPosition{ static_cast<short>(tilePosition.x / (chunkSize*Tile::tileSize)), static_cast<short>(tilePosition.y / (chunkSize*Tile::tileSize)) };
		return chunks.at(chunkPosition.x).at(chunkPosition.y).getTile(Position<short>{static_cast<short>(tilePosition.x - chunkPosition.x*chunkSize*Tile::tileSize),
			static_cast<short>(tilePosition.y - chunkPosition.y*chunkSize*Tile::tileSize)});
	}
	~Map();
private:
	class Chunk {
	public:
		Chunk(short x, short y);//Position in chunk
		Chunk(short x, short y, std::array<unsigned char, chunkSize*chunkSize> chunkMap);//Create a chunk with predefined map
		void render(SDL_Renderer* renderer, const Camera& camera) const;
		const Tile& getTile(const Position<short>& tilePosition) const {//Position in pixel relative to the chunk
			return *tiles[tilePosition.x / Tile::tileSize][tilePosition.y / Tile::tileSize];
		}
	private:
		const Position<short> position;
		std::array<std::array<std::shared_ptr<Tile>, chunkSize>, chunkSize> tiles;
	};

	std::map<short, std::map<short, Chunk>> chunks;
};

