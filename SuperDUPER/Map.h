#pragma once
//#include "Chunk.h"
#include "Camera.h"
#include <vector>
#include <memory>
#include <array>
#include "Tile.h"

class Map
{
public:
	Map();
	void render(SDL_Renderer* renderer, const Camera& viewport) const;
	constexpr static int chunkSize{ 100 };
	constexpr static int nbrOfTile{ chunkSize * chunkSize };
	~Map();
private:
	class Chunk {
	public:
		Chunk(int x, int y);
		void render(SDL_Renderer* renderer, const Camera& viewport) const;
	private:
		const Position<> position;
		std::array<std::shared_ptr<Tile>, nbrOfTile> tiles;
	};

	std::vector<Chunk> chunks;
};

