#pragma once
#include "Struct/Position.h"
class LifeForm;
class Destination
{
public:
	Destination();
	Destination(Position<> coordinate);
	Destination(LifeForm* entity);
	Position<float> getCoordinate() const;
	LifeForm* getEntity() const { return entity; }
	~Destination();
private:
	Position<> coordinate;
	LifeForm* entity = nullptr;
};

