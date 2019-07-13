#pragma once
#include <SDL.h>
#include "../Renderable/GraphicRect.h"
class LifeForm;
class Tile
{
public:
	//The x and y are position in pixel of top left of the tile
	Tile(long x, long y, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport) const;
	virtual bool isWalkable() const = 0;//Indicate if a life form can walk on the tile
	virtual bool isDestructible() const = 0;
	virtual bool isTraversable() const = 0;//Indicate if a projectile can get past the tile
	virtual void effectOnLifeForm(LifeForm* lifeForm) const = 0;
	const Position<>& getPosition() const { return position; }
	~Tile();
	constexpr static int tileSize = 30;
private:
	Position<> position;
	GraphicRect tileGraphic;
};

