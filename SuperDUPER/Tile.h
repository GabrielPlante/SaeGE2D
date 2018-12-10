#pragma once
#include <SDL.h>
#include "Rect.h"
class Tile
{
public:
	//The x and y are relative to the tile, not the pixel
	Tile(int x, int y, Color color);
	void render(SDL_Renderer* renderer, const Viewport& viewport);
	virtual bool isWalkable() = 0;
	virtual bool isDestructible() = 0;
	~Tile();
	constexpr static int tileSize = 10;
private:
	Rect tileGraphic;
};

