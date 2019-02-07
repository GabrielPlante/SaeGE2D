#include "Destination.h"
#include "LifeForm.h"


Destination::Destination(){}

Destination::Destination(Position<> coordinate)
	:coordinate{ coordinate }
{
}

Destination::Destination(LifeForm* entity)
	: entity{ entity }
{
}

Position<double> Destination::getCoordinate() const {
	if (entity != nullptr)
		return entity->getPosition();
	else//There is surely something better to do
		return Position<double>{static_cast<double>(coordinate.x), static_cast<double>(coordinate.y)};
}

Destination::~Destination()
{
}
