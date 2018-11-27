#include "Renderable.h"



Renderable::Renderable(int x, int y, int w, int h){
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}

const SDL_Rect* Renderable::getRect() {
	return &rect;
}

Renderable::~Renderable()
{
}
