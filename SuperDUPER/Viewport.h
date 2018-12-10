#pragma once
#include <SDL.h>
#include "Rectangle.h"

class Viewport
{
public:
	Viewport(int x, int y, int w, int h);
	void move(int deltaX, int deltaY);
	void resize(double deltaW, double deltaH);
	bool isInViewport(const Rectangle& object) const;
	void applyViewport(SDL_Renderer* renderer);
	~Viewport();
private:
	Rectangle viewport;
};

