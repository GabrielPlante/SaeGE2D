#include "../../header/Renderable/Circle.h"


Circle::Circle(int radius, Color color)
	: Renderable(), color{ color }, radius{ radius }
{
}

void Circle::render(SDL_Renderer* renderer, const Camera& camera, const Position<>& position) const {
	if (camera.isInCamera(Rectangle(position.x - radius, position.y - radius, radius * 2, radius * 2))) {
		//This color will be the one of the circle
		SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
		
		//The position relative to the screen is used to render the circle
		Position<> relativePosition{ camera.absoluteToRelative(position.x, position.y) };
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

//Optimised way to find if a point is in the circle
bool Circle::pointIsIn(const Position<>& point, const Position<>& position) const {
	const int dx = abs(point.x - position.x);
	if (dx > radius) return false;
	const int dy = abs(point.y - position.y);
	if (dy > radius) return false;
	return dx * dx + dy * dy <= radius * radius;
}


Circle::~Circle()
{
}
