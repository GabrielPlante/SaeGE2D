#include "Circle.h"


Circle::Circle(int x, int y, int radius, Color color)
	: Renderable(x, y, radius, radius) {
	this->color = color;
	for (int rad = radius; rad > radius * 2 / 3; rad--) {
		x = rad - 1;
		y = 0;
		int dx = 1;
		int dy = 1;
		int err = dx - (rad << 1);

		while (x >= y)
		{
			//  Each of the following renders an octant of the circle
			SDL_Point point;
			point.x = rect.x + x; point.y = rect.y - y;
			circlePoints.emplace_back(point);
			point.x = rect.x + x; point.y = rect.y + y;
			circlePoints.emplace_back(point);
			point.x = rect.x - x; point.y = rect.y - y;
			circlePoints.emplace_back(point);
			point.x = rect.x - x; point.y = rect.y + y;
			circlePoints.emplace_back(point);
			point.x = rect.x + y; point.y = rect.y - x;
			circlePoints.emplace_back(point);
			point.x = rect.x + y; point.y = rect.y - x;
			circlePoints.emplace_back(point);
			point.x = rect.x + y; point.y = rect.y + x;
			circlePoints.emplace_back(point);
			point.x = rect.x - y; point.y = rect.y - x;
			circlePoints.emplace_back(point);
			point.x = rect.x - y; point.y = rect.y + x;
			circlePoints.emplace_back(point);

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

void Circle::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);//This color will be the one of the circle
	SDL_Point* points = &circlePoints[0];//Convert from vector to array
	SDL_RenderDrawPoints(renderer, points, circlePoints.size());
}

Circle::~Circle()
{
}
