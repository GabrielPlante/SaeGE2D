#pragma once
#include <vector>
#include <array>
#include <memory>
#include "Tile.h"
#include "IntPosition.h"
class Chunk
{
public:
	Chunk(int x, int y);
	void render(SDL_Renderer* renderer, const Camera& viewport);
	~Chunk();
	constexpr static int chunkSize{ 100 };
	constexpr static int nbrOfTile{ chunkSize * chunkSize };
private:
	const IntPosition position;
	std::array<std::shared_ptr<Tile>, nbrOfTile> tiles;
	bool isInitialised{ false };
};

