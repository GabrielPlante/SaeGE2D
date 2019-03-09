#pragma once
#include "Renderable.h"
#include "Color.h"

//The graphic representation of a rectangle
//The position of the rectanle is the position of the left upper corner
class GraphicRect : public Renderable
{
public:
	GraphicRect(short w, short h, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport, const Position<>& position) const override;
	bool pointIsIn(const Position<>& point, const Position<>& position) const override;
	~GraphicRect();
protected:
	short w;
	short h;
	Color color;
};
