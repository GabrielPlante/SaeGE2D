#pragma once
#include <SDL.h>

class Renderable
{
public:
	Renderable(int x, int y, int w, int h);
	const SDL_Rect* getRect();
	virtual void render(SDL_Renderer* renderer) = 0;
	~Renderable();
protected:
	SDL_Rect rect;
};

