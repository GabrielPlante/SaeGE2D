#include "Tile.h"



Tile::Tile(int x, int y, Color color)
	:position{ x+tileSize/2, y+tileSize/2 }, tileGraphic { tileSize, tileSize, color }
{
}

void Tile::render(SDL_Renderer* renderer, const Camera& camera) const {
	tileGraphic.render(renderer, camera, position);
}

Tile::~Tile()
{
}
