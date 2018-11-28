#include "Rect.h"


Rect::Rect(int x, int y, int w, int h, Color color)
	:Renderable(x, y) {
	this->color = color;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

void Rect::setPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
}

void Rect::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
	SDL_RenderFillRect(renderer, &rect);
}

Rect::~Rect()
{
}
