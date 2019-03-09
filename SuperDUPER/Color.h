#pragma once
#include <SDL.h>
struct Color {
	int red;
	int green;
	int blue;
	int transparency;
	Color(){}
	Color(int r, int g, int b, int a = 255) {
		red = r; green = g; blue = b; transparency = a;
	}
	SDL_Color toSDLColor() { return SDL_Color{ static_cast<Uint8>(red), static_cast<Uint8>(green), static_cast<Uint8>(blue), static_cast<Uint8>(transparency) }; }
};
