#pragma once
#include "Tile.h"
class BedRock :
	public Tile
{
public:
	BedRock(int x, int y);
	bool isWalkable() const override { return false; }
	bool isDestructible() const override { return false; }
	bool isTraversable() const override { return false; }
	~BedRock();
};

