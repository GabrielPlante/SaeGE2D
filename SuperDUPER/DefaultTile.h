#pragma once
#include "Tile.h"
class DefaultTile :
	public Tile
{
public:
	DefaultTile(int x, int y);
	bool isWalkable() override { return true; }
	bool isDestructible() override { return false; }
	bool isTraversable() override { return true; }
	~DefaultTile();
};

