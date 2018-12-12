#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>
#include <array>
#include "IntPosition.h"

struct DoublePosition
{
	double x;
	double y;
	DoublePosition() {}
	DoublePosition(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double angle(IntPosition destination) {//Find the angle between the point and the direction
		constexpr double PI = 3.14159265;
		double directionAngle = 0;
		directionAngle = atan2(-(destination.y - y), destination.x - x);
		if (directionAngle < 0)
			directionAngle = abs(directionAngle);
		else
			directionAngle = 2 * PI - directionAngle;
		return directionAngle;
	}
};

class Entity
{
public:
	Entity(double x, double y);
	void render(SDL_Renderer* renderer, const Camera& viewport);
	virtual bool refresh() = 0;//Return true if the entity doesn't exist anymore, else false
	IntPosition chunkPosition() const;
	~Entity();
protected:
	std::unique_ptr<Renderable> shape;
	DoublePosition position;
};

