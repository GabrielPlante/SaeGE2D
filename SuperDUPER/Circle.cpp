#include "Circle.h"



Circle::Circle(int x, int y, int radius, Color color)
	: Renderable(x, y, radius, radius) {
	this->color = color;
}

void Circle::render(SDL_Renderer* renderer) {
	int radius = rect.h;
	int x = radius;
	int y = 0;
	int err = 0;

	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, rect.x + x, rect.y - y);
		SDL_RenderDrawPoint(renderer, rect.x + x, rect.y + y);
		SDL_RenderDrawPoint(renderer, rect.x - x, rect.y - y);
		SDL_RenderDrawPoint(renderer, rect.x - x, rect.y + y);
		SDL_RenderDrawPoint(renderer, rect.x + y, rect.y - x);
		SDL_RenderDrawPoint(renderer, rect.x + y, rect.y + x);
		SDL_RenderDrawPoint(renderer, rect.x - y, rect.y - x);
		SDL_RenderDrawPoint(renderer, rect.x - y, rect.y + x);

		if (err <= 0)
		{
			y++;
			err += 2*y+1;
		}
		if (err > 0)
		{
			x--;
			err -= 2 * x + 1;
		}
	}
}

Circle::~Circle()
{
}
