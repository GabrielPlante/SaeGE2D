#pragma once
#include "Tile.h"
class DefaultTile :
	public Tile
{
public:
	DefaultTile(long x, long y);
	bool isWalkable() const override { return true; }
	bool isDestructible() const override { return false; }
	bool isTraversable() const override { return true; }
	void effectOnLifeForm(LifeForm* lifeForm) const override {}
	~DefaultTile();
};

