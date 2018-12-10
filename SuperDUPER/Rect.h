#pragma once
#include "Renderable.h"
#include "Color.h"

//The graphic representation of a rectangle
class Rect : public Renderable
{
public:
	Rect(int x, int y, int w, int h, Color color);
	void setPosition(int x, int y) override;
	void render(SDL_Renderer* renderer, const Viewport& viewport) override;
	~Rect();
protected:
	SDL_Rect rect;
	Color color;
};

