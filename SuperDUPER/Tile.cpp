#include "Tile.h"



Tile::Tile(int x, int y, Color color)
	:tileGraphic{ x, y, tileSize, tileSize, color }
{
}

void Tile::render(SDL_Renderer* renderer, const Viewport& viewport) {
	tileGraphic.render(renderer, viewport);
}

Tile::~Tile()
{
}
