#pragma once
#include <SDL.h>
#include "Camera.h"

class Renderable
{
public:
	Renderable(int x, int y);
	virtual void render(SDL_Renderer* renderer, const Camera& camera) = 0;
	void setPosition(long int x, long int y);
	IntPosition getRelativePosition(const Camera& camera) const;
	virtual bool pointIsIn(IntPosition point) = 0;
	~Renderable();
protected:
	IntPosition position;
};

