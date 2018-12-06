#pragma once
#include "Tile.h"
#include <vector>

class Map
{
public:
	Map();
	void render(SDL_Renderer* renderer);
	~Map();
private:
	std::vector<Tile> tiles;
};

