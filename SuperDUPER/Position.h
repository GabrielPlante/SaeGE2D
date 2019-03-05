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
	//http://mathworld.wolfram.com/Circle-LineIntersection.html
	//Return true if the line formed by this position and the endLinePoint intersect with the given circle
	bool lineIntersectCircle(const Position<T>& endLinePoint, const Position<>& circlePosition, short circleRadius) {
		short x1 = static_cast<short>(x - circlePosition.x);
		short y1 = static_cast<short>(y - circlePosition.y);
		short x2 = static_cast<short>(endLinePoint.x - circlePosition.x);
		short y2 = static_cast<short>(endLinePoint.y - circlePosition.y);
		return pow(circleRadius, 2)*(pow(x2 - x1, 2) + pow(y2 - y1, 2)) - pow(x1*y2 - x2 * y1, 2) >= 0;
	}
	//https://yal.cc/rectangle-circle-intersection-test/
	//Return true if the rectangle intersect the circle
	//The position x and y are the circle position and the rectangle position should be the center of the rectangle
	bool rectIntersectCircle(const Position<>& rectanglePosition, short w, short h, short circleRadius) {
		short deltaX = static_cast<short>(x - max(rectanglePosition.x, min(x, rectanglePosition.x + w)));
		short deltaY = static_cast<short>(y - max(rectanglePosition.y, min(y, rectanglePosition.x + h)));
		return (pow(deltaX, 2) + pow(deltaY, 2)) <= pow(circleRadius, 2);
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

