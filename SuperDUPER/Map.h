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
	constexpr static int chunkSize{ 100 };//Number of tile per line in the chunk
	const Tile& getTile(const Position<>& tilePosition) const {//Position in absolute in pixel
		Position<> chunkPosition{ tilePosition.x / (chunkSize*Tile::tileSize), tilePosition.y / (chunkSize*Tile::tileSize) };
		return chunks.at(chunkPosition.x).at(chunkPosition.y).getTile(Position<>{tilePosition.x - chunkPosition.x, tilePosition.y - chunkPosition.y});
	}
	~Map();
private:
	class Chunk {
	public:
		Chunk(int x, int y);//Position in chunk
		void render(SDL_Renderer* renderer, const Camera& camera) const;
		const Tile& getTile(const Position<>& tilePosition) const {//Position in pixel relative to the chunk
			return *tiles.at(tilePosition.x / Tile::tileSize).at(tilePosition.y / Tile::tileSize);
		}
	private:
		const Position<> position;
		std::map<long, std::map<long, std::shared_ptr<Tile>>> tiles;
	};

	std::map<long, std::map<long, Chunk>> chunks;

};

