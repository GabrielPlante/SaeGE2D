#pragma once
#include "Chunk.h"
#include <vector>

class Map
{
public:
	Map();
	void render(SDL_Renderer* renderer);
	~Map();
private:
	std::vector<Chunk> chunks;
};

