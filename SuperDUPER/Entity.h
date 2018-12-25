#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>
#include <array>
#include "Position.h"

struct DoublePosition
{
	double x;
	double y;
	DoublePosition() {}
	DoublePosition(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

class Entity
{
public:
	Entity(double x, double y);
	void render(SDL_Renderer* renderer, const Camera& viewport);
	virtual bool refresh() = 0;//Return true if the entity doesn't exist anymore, else false
	//Position<> chunkPosition() const;
	Position<double> getPosition() const;
	bool pointIsOnThis(Position<> point) const;
	~Entity();
protected:
	std::unique_ptr<Renderable> shape;
	Position<double> position;
};

