#pragma once
#include "Position.h"
class LifeForm;
class Destination
{
public:
	Destination();
	Destination(Position<> coordinate);
	Destination(LifeForm* entity);
	Position<double> getCoordinate() const;
	LifeForm* getEntity() const { return entity; }
	~Destination();
private:
	Position<> coordinate;
	LifeForm* entity = nullptr;
};

