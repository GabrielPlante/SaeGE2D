#pragma once
#include "IntPosition.h"
#include "Entity.h"
class Destination
{
public:
	Destination();
	Destination(IntPosition coordinate);
	Destination(Entity* entity);
	IntPosition getCoordinate() const;
	~Destination();
private:
	IntPosition coordinate;
	Entity* entity = nullptr;
};

