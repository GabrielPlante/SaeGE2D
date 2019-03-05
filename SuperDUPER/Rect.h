#pragma once
#include "Renderable.h"
#include "Color.h"

//The graphic representation of a rectangle
class Rect : public Renderable
{
public:
	Rect(short w, short h, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport, const Position<>& position) const override;
	bool pointIsIn(const Position<>& point, const Position<>& position) const override;
	~Rect();
protected:
	short w;
	short h;
	Color color;
};

