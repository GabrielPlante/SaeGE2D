#pragma once
#include "Tile.h"
class DefaultTile :
	public Tile
{
public:
	DefaultTile(int x, int y);
	bool isWalkable() override;
	bool isDestructible() override;
	~DefaultTile();
};

