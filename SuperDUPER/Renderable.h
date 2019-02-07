#pragma once
#include <SDL.h>
#include "Camera.h"

class Renderable
{
public:
	Renderable(int x, int y);
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	void setPosition(long int x, long int y);
	Position<> getRelativePosition(const Camera& camera) const;
	virtual bool pointIsIn(Position<> point) const = 0;
	~Renderable();
protected:
	Position<> position;
};

