#pragma once
#include <SDL.h>
struct IntPosition
{
	long int x;
	long int y;
	IntPosition(long int x, long int y) {
		this->x = x;
		this->y = y;
	}
	IntPosition(const SDL_Point& point)
		:x{ point.x }, y{ point.y }
	{
	}
	IntPosition(){}
	SDL_Point toSDL_Point() const {
		SDL_Point point;
		point.x = x;
		point.y = y;
		return point;
	}
};
