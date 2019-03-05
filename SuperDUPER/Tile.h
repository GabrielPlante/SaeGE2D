#pragma once
#include <SDL.h>
#include "Rect.h"
class Tile
{
public:
	//The x and y are relative to the tile, not the pixel
	Tile(int x, int y, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport) const;
	virtual bool isWalkable() = 0;//Indicate if a life form can walk on the tile
	virtual bool isDestructible() = 0;
	virtual bool isTraversable() = 0;//Indicate if a projectile can get past the tile
	~Tile();
	constexpr static int tileSize = 30;
private:
	Position<> position;
	Rect tileGraphic;
};

