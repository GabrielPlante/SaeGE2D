#pragma once
#include "Tile.h"
class BedRock :
	public Tile
{
public:
	BedRock(int x, int y);
	bool isWalkable() override { return false; }
	bool isDestructible() override { return false; }
	bool isTraversable() override { return false; }
	~BedRock();
};

