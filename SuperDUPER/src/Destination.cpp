#include "../header/Destination.h"
#include "../header/Entities/LifeForm.h"


Destination::Destination(){}

Destination::Destination(Position<> coordinate)
	:coordinate{ coordinate }
{
}

Destination::Destination(LifeForm* entity)
	: entity{ entity }
{
}

Position<float> Destination::getCoordinate() const {
	if (entity != nullptr)
		return entity->getPosition();
	else//There is surely something better to do
		return Position<float>{static_cast<float>(coordinate.x), static_cast<float>(coordinate.y)};
}

Destination::~Destination()
{
}
