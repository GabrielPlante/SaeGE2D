#include "Circle.h"


Circle::Circle(int x, int y, int radius, Color color)
	: Renderable(x, y), color{ color }, radius{ radius }
{
}

void Circle::render(SDL_Renderer* renderer, const Camera& camera) {
	if (camera.isInCamera(Rectangle(position.x - radius, position.y - radius, radius * 2, radius * 2))) {
		//This color will be the one of the circle
		SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
		
		//The position relative to the screen is used to render the circle
		IntPosition relativePosition{ getRelativePosition(camera) };
		//The middle point algorithm
		int rad = radius;
		int x = rad - 1;
		int y = 0;
		int dx = 1;
		int dy = 1;
		int err = dx - (rad << 1);

		while (x >= y)
		{
			//Draw every line between two opposite point
			SDL_RenderDrawLine(renderer, relativePosition.x - x, relativePosition.y - y, relativePosition.x + x, relativePosition.y - y);
			SDL_RenderDrawLine(renderer, relativePosition.x - y, relativePosition.y + x, relativePosition.x + y, relativePosition.y + x);
			SDL_RenderDrawLine(renderer, relativePosition.x - y, relativePosition.y - x, relativePosition.x + y, relativePosition.y - x);
			SDL_RenderDrawLine(renderer, relativePosition.x - x, relativePosition.y + y, relativePosition.x + x, relativePosition.y + y);
			if (err <= 0)
			{
				y++;
				err += dy;
				dy += 2;
			}
			if (err > 0)
			{
				x--;
				dx += 2;
				err += dx - (rad << 1);
			}
		}
	}
}

Circle::~Circle()
{
}
