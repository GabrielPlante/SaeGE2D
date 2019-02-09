#pragma once
#include <SDL.h>
#include "Camera.h"
class Projectile
{
public:
	Projectile();
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	virtual bool refresh() = 0;//Return true if the projectile doesn't exist anymore
	~Projectile();
};

