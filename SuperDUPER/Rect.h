#pragma once
#include "Renderable.h"
#include "Color.h"

//The graphic representation of a rectangle
class Rect : public Renderable
{
public:
	Rect(int x, int y, int w, int h, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport) override;
	bool pointIsIn(Position<> point) const override;
	~Rect();
protected:
	Rectangle rect;
	Color color;
};

