#include "Rect.h"


Rect::Rect(int x, int y, int w, int h, Color color)
	:Renderable(x, y, w, h) {
	this->color = color;
}

void Rect::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.transparency);
	SDL_RenderFillRect(renderer, &rect);
}

Rect::~Rect()
{
}
