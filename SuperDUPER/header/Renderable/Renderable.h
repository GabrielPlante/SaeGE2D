#pragma once
#include <SDL.h>
#include "../Camera.h"

class Renderable
{
public:
	Renderable();
	virtual void render(SDL_Renderer* renderer, const Camera& camera, const Position<>& position) const = 0;
	virtual bool pointIsIn(const Position<>& point, const Position<>& position) const = 0;
	~Renderable();
};

