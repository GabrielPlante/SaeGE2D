#include "GraphicRect.h"
#include "Rectangle.h"

GraphicRect::GraphicRect(short w, short h, Color color)
	:Renderable(), w{ w }, h{ h }, color{ color }
{
}

void GraphicRect::render(SDL_Renderer* renderer, const Camera& camera, const Position<>& position) const {
	if (camera.isInCamera(Rectangle{ position, w, h })) {
		SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
		//Converting the coordinate to relative position
		Position<> relativePosition{ camera.absoluteToRelative(position.x, position.y) };
		SDL_RenderFillRect(renderer, &Rectangle{ relativePosition.x, relativePosition.y, w, h }.toSDL_Rect());
	}
}

bool GraphicRect::pointIsIn(const Position<>& point, const Position<>& position) const {
	if (abs(point.x - position.x) > w)
		return false;
	if (abs(point.y - position.y) > h)
		return false;
	return true;
}

GraphicRect::~GraphicRect()
{
}