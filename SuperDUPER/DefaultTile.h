#pragma once
#include "Tile.h"
class DefaultTile :
	public Tile
{
public:
	DefaultTile(int x, int y);
	bool isWalkable() const override { return true; }
	bool isDestructible() const override { return false; }
	bool isTraversable() const override { return true; }
	~DefaultTile();
};

