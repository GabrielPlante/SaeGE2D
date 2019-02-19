#pragma once
#include <SDL.h>
#include "Angle.h"
template <typename T = long int>
struct Position
{
	T x;
	T y;
	Position(T x, T y) {
		this->x = x;
		this->y = y;
	}
	Position(const SDL_Point& point)
		:x{ point.x }, y{ point.y }
	{
	}
	Position(){}
	SDL_Point toSDL_Point() const {
		SDL_Point point;
		point.x = static_cast<int>(x);
		point.y = static_cast<int>(y);
		return point;
	}
	Angle angle(const Position<float> destination) const {//Find the angle between the point and the direction
		constexpr float PI = 3.14159265f;
		Angle directionAngle{ static_cast<float>(atan2(-(destination.y - y), destination.x - x)) };
		if (directionAngle.get() < 0)
			directionAngle.set(std::abs(directionAngle.get()));
		else
			directionAngle.set(2 * PI - directionAngle.get());
		return directionAngle;
	}
	int distanceSquared(const Position<float> destination) const {
		return static_cast<int>(pow(x - destination.x, 2) + pow(y - destination.y, 2));
	}
	int distanceSquared(const Position<> destination) const {
		return distanceSquared(Position<float>{static_cast<float>(destination.x), static_cast<float>(destination.y)});
	}
	bool operator==(const Position<T>& other) {
		return x == other.x && y == other.y;
	}
};

