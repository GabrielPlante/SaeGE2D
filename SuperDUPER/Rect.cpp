#include "Rect.h"
#include "Rectangle.h"

Rect::Rect(int x, int y, int w, int h, Color color)
	:Renderable(x, y), rect{ x, y, w, h }, color{ color }
{
}

void Rect::render(SDL_Renderer* renderer, const Camera& camera) const {
	if (camera.isInCamera(rect)) {
		SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
		//Converting the coordinate to relative position
		Position<> relativePosition{ getRelativePosition(camera) };
		SDL_RenderFillRect(renderer, &Rectangle{ relativePosition.x - rect.w / 2, relativePosition.y - rect.h / 2, rect.w, rect.h }.toSDL_Rect());
	}
}

bool Rect::pointIsIn(Position<> point) const {
	if (abs(point.x - position.x + rect.w / 2) > rect.w)
		return false;
	if (abs(point.y - position.y + rect.h / 2) > rect.h)
		return false;
	return true;
}

Rect::~Rect()
{
}
