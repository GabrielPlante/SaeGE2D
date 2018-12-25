#pragma once
#include <SDL.h>
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
	double angle(Position<double> destination) {//Find the angle between the point and the direction
		constexpr double PI = 3.14159265;
		double directionAngle = 0;
		directionAngle = atan2(-(destination.y - y), destination.x - x);
		if (directionAngle < 0)
			directionAngle = std::abs(directionAngle);
		else
			directionAngle = 2 * PI - directionAngle;
		return directionAngle;
	}
};

