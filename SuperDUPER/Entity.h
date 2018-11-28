#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>
class Entity
{
public:
	Entity();
	void render(SDL_Renderer* renderer);
	virtual bool refresh() = 0;
	~Entity();
protected:
	std::unique_ptr<Renderable> shape;
};

