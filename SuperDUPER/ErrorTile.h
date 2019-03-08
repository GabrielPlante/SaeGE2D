#pragma once
#include "Tile.h"
class ErrorTile :
	public Tile
{
public:
	ErrorTile(long x, long y);
	bool isWalkable() const override { return true; }
	bool isDestructible() const override { return false; }
	bool isTraversable() const override { return true; }
	void effectOnLifeForm(LifeForm* lifeForm) const override {}
	~ErrorTile();
};

