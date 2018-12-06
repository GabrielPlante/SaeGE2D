#pragma once
#include <SDL.h>
#include "Rect.h"
#include <memory>
class Tile
{
public:
	//The x and y are relative to the tile, not the pixel
	Tile(int x, int y, Color color);
	void render(SDL_Renderer* renderer);
	virtual bool isWalkable() = 0;
	virtual bool isDestructible() = 0;
	~Tile();
private:
	std::unique_ptr<Rect> tileGraphic;
};

