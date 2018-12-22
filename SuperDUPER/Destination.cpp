#include "Destination.h"


Destination::Destination(){}

Destination::Destination(Position<> coordinate)
	:coordinate{ coordinate }
{
}

Destination::Destination(Entity* entity)
	: entity{ entity }
{
}

Position<> Destination::getCoordinate() const {
	if (entity != nullptr)
		return entity->getPosition();
	else
		return coordinate;
}

Destination::~Destination()
{
}
