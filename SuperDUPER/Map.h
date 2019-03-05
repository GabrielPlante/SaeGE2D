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
		return chunks.at(chunkPosition.x).at(chunkPosition.y).getTile(Position<short>{static_cast<short>(tilePosition.x - chunkPosition.x), static_cast<short>(tilePosition.y - chunkPosition.y)});
	}
	~Map();
private:
	class Chunk {
	public:
		Chunk(int x, int y);//Position in chunk
		void render(SDL_Renderer* renderer, const Camera& camera) const;
		const Tile& getTile(const Position<short>& tilePosition) const {//Position in pixel relative to the chunk
			return *tiles.at(tilePosition.x / Tile::tileSize).at(tilePosition.y / Tile::tileSize);
		}
	private:
		const Position<short> position;
		std::map<short, std::map<short, std::shared_ptr<Tile>>> tiles;
	};

	std::map<short, std::map<short, Chunk>> chunks;
};

