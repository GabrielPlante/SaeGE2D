#include "Tile.h"



Tile::Tile(long x, long y, Color color)
	:position{ x, y }, tileGraphic { tileSize, tileSize, color }
{
}

void Tile::render(SDL_Renderer* renderer, const Camera& camera) const {
	tileGraphic.render(renderer, camera, position);
}

Tile::~Tile()
{
}
