#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>

struct Position
{
	double x;
	double y;
	Position() {}
	Position(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

class Entity
{
public:
	Entity(double x, double y);
	void render(SDL_Renderer* renderer);
	virtual bool refresh() = 0;//Return true if the entity doesn't exist anymore, else false
	~Entity();
protected:
	std::unique_ptr<Renderable> shape;
	Position position;
};

