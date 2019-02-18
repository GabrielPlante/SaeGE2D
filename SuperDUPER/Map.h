#pragma once
#include "Camera.h"
#include <vector>
#include <memory>
#include <array>
#include "Tile.h"

class Map
{
public:
	Map();
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	constexpr static int chunkSize{ 100 };//Number of tile per line in the chunk
	~Map();
private:
	class Chunk {
	public:
		Chunk(int x, int y);
		void render(SDL_Renderer* renderer, const Camera& camera) const;
	private:
		const Position<> position;
		std::array<std::array<std::shared_ptr<Tile>, chunkSize>, chunkSize> tiles;
	};

	std::vector<std::vector<Chunk>> chunks{ 1 };
};

