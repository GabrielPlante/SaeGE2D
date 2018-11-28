#include "Circle.h"


Circle::Circle(int x, int y, int radius, Color color)
	: Renderable(x, y) {
	this->color = color;
	this->radius = radius;
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
			point.x = position.x + x; point.y = position.y - y;
			circlePoints.emplace_back(point);
			point.x = position.x + x; point.y = position.y + y;
			circlePoints.emplace_back(point);
			point.x = position.x - x; point.y = position.y - y;
			circlePoints.emplace_back(point);
			point.x = position.x - x; point.y = position.y + y;
			circlePoints.emplace_back(point);
			point.x = position.x + y; point.y = position.y - x;
			circlePoints.emplace_back(point);
			point.x = position.x + y; point.y = position.y - x;
			circlePoints.emplace_back(point);
			point.x = position.x + y; point.y = position.y + x;
			circlePoints.emplace_back(point);
			point.x = position.x - y; point.y = position.y - x;
			circlePoints.emplace_back(point);
			point.x = position.x - y; point.y = position.y + x;
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

void Circle::setPosition(int x, int y) {
	if (x != position.x && y != position.y) {
		int deltaX = 0;
		if (x != position.x) {
			deltaX = x - position.x;
			position.x = x;
		}
		int deltaY = 0;
		if (y != position.y) {
			deltaY = y - position.y;
			position.y = y;
		}
		for (auto it = circlePoints.begin(); it != circlePoints.end(); it++) {
			it->x += deltaX;
			it->y += deltaY;
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
