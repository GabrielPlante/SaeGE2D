#pragma once
#include "Position.h"
#include "Entity.h"
class Destination
{
public:
	Destination();
	Destination(Position<> coordinate);
	Destination(Entity* entity);
	Position<double> getCoordinate() const;
	Entity* getEntity() { return entity; }
	~Destination();
private:
	Position<> coordinate;
	Entity* entity = nullptr;
};

