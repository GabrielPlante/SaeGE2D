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

void GraphicRect::renderWithoutCamera(SDL_Renderer* renderer, const Position<>& position) const {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
	SDL_RenderFillRect(renderer, &Rectangle{ position.x, position.y, w, h }.toSDL_Rect());
}

GraphicRect::~GraphicRect()
{
}
