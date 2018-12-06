#include "Tile.h"



Tile::Tile(int x, int y, Color color)
{
	constexpr int tileSize = 10;
	tileGraphic = std::unique_ptr<Rect>{ new Rect(x*tileSize, y*tileSize, tileSize, tileSize, color) };
}

void Tile::render(SDL_Renderer* renderer) {
	tileGraphic->render(renderer);
}

Tile::~Tile()
{
}
