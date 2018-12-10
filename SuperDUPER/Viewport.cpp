#include "Viewport.h"



Viewport::Viewport(int x, int y, int w, int h)
	:viewport{ x, y, w, h }
{
}

void Viewport::move(int deltaX, int deltaY) {
	viewport.x += deltaX;
	viewport.y += deltaY;
}

void Viewport::resize(double deltaW, double deltaH) {
	viewport.w = static_cast<int>(viewport.w*deltaW);
	viewport.h = static_cast<int>(viewport.h*deltaH);
}

bool Viewport::isInViewport(const Rectangle& object) const {
	return viewport.overlap(object);
}

void Viewport::applyViewport(SDL_Renderer* renderer) {
	SDL_RenderSetViewport(renderer, &viewport.toSDL_Rect());
}

Viewport::~Viewport()
{
}
