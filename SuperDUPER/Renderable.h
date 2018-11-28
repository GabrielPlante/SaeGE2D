#pragma once
#include <SDL.h>

class Renderable
{
public:
	Renderable(int x, int y);
	const SDL_Point* getPosition();
	virtual void setPosition(int x, int y) = 0;
	virtual void render(SDL_Renderer* renderer) = 0;
	~Renderable();
protected:
	SDL_Point position;
};

