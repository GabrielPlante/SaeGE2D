#pragma once
#include "Tile.h"
class BedRock :
	public Tile
{
public:
	BedRock(long x, long y);
	bool isWalkable() const override { return false; }
	bool isDestructible() const override { return false; }
	bool isTraversable() const override { return false; }
	void effectOnLifeForm(LifeForm* lifeForm) const override {}
	~BedRock();
};

