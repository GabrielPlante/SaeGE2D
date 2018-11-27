#pragma once
#include "Renderable.h"
#include "Color.h"

class Rect : public Renderable
{
public:
	Rect(int x, int y, int w, int h, Color color);
	void render(SDL_Renderer* renderer) override;
	~Rect();
protected:
	Color color;
};

