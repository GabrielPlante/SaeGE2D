#pragma once
#include "Tile.h"
class BedRock :
	public Tile
{
public:
	BedRock(int x, int y);
	bool isWalkable() override;
	bool isDestructible() override;
	~BedRock();
};

