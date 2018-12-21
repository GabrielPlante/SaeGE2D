#include "Destination.h"


Destination::Destination(){}

Destination::Destination(IntPosition coordinate)
	:coordinate{ coordinate }
{
}

Destination::Destination(Entity* entity)
	: entity{ entity }
{
}

IntPosition Destination::getCoordinate() const {
	if (entity != nullptr)
		return entity->getPosition();
	else
		return coordinate;
}

Destination::~Destination()
{
}
