#include "Renderable.h"



Renderable::Renderable(int x, int y){
	position.x = x;
	position.y = y;
}

const SDL_Point* Renderable::getPosition() {
	return &position;
}

Renderable::~Renderable()
{
}
