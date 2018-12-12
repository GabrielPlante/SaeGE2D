#pragma once
#include <SDL.h>
#include "IntPosition.h"

//A simple rectangle
struct Rectangle{
	long int x;
	long int y;
	int w;
	int h;
	Rectangle() {}
	Rectangle(const SDL_Rect& rect)
		:x{ rect.x }, y{ rect.y }, w{ rect.w }, h{ rect.h }
	{
	}
	Rectangle(const IntPosition& position, const int w, const int h)
		:x{ position.x }, y{ position.y }, w{ w }, h{ h }
	{
	}
	Rectangle(const int x, const int y, const int w, const int h)
		:x{ x }, y{ y }, w{ w }, h{ h }
	{
	}
	SDL_Rect toSDL_Rect() {
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		return rect;
	}
	bool overlap(const Rectangle& rectangle) const {
		//Check if an rectangle is more left than the other
		if (x > rectangle.x + rectangle.w || rectangle.x > x + w)
			return false;
		//Check if an rectangle is above the other
		if (y > rectangle.y + rectangle.h || rectangle.y > y + h)
			return false;
		return true;
	}
};