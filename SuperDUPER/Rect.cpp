#include "Rect.h"
#include "Rectangle.h"

Rect::Rect(int x, int y, int w, int h, Color color)
	:Renderable(x, y), rect{ x, y, w, h }, color{ color }
{
}

void Rect::render(SDL_Renderer* renderer, const Camera& camera) {
	if (camera.isInCamera(rect)) {
		SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
		//Converting the coordinate to relative position
		SDL_RenderFillRect(renderer, &Rectangle{ getRelativePosition(camera), rect.w, rect.h }.toSDL_Rect());
	}
}

Rect::~Rect()
{
}
