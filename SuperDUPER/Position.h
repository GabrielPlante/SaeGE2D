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
	Angle angle(const Position<double> destination) const {//Find the angle between the point and the direction
		constexpr double PI = 3.14159265;
		Angle directionAngle{ atan2(-(destination.y - y), destination.x - x) };
		if (directionAngle.get() < 0)
			directionAngle.set(std::abs(directionAngle.get()));
		else
			directionAngle.set(2 * PI - directionAngle.get());
		return directionAngle;
	}
	int distanceSquared(const Position<double> destination) const {
		return static_cast<int>(pow(x - destination.x, 2) + pow(y - destination.y, 2));
	}
	bool operator==(const Position<T>& other) {
		return x == other.x && y == other.y;
	}
	bool lineIntersectWithCircle(Position<> endLine, Position<> circlePos, int circleRad) {
		long x1 = static_cast<long>(x);
		long y1 = static_cast<long>(y);
		if (x1 != endLine.x || y1 != endLine.y)
			return pow((endLine.x - x1)*circlePos.x + (y1 - endLine.y)*circlePos.y + (x1 - endLine.x)*circlePos.y + (endLine.y - y1)*x1, 2)
				/ (pow(endLine.x - x1, 2) + pow(y1 - endLine.y, 2)) <= pow(circleRad, 2);
		return pow(x1 - circlePos.x, 2) + pow(y1 - circlePos.y, 2) <= pow(circleRad, 2);
	}
};

