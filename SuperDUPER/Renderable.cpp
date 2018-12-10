#include "Renderable.h"



Renderable::Renderable(int x, int y){
	position.x = x;
	position.y = y;
}

void Renderable::setPosition(long int x, long int y) {
	position.x = x;
	position.y = y;
}

IntPosition Renderable::getRelativePosition(const Camera& camera) const {
	return camera.absoluteToRelative(position.x, position.y);
}

Renderable::~Renderable()
{
}
