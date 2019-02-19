#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>
#include <array>
#include "Position.h"
#include <vector>

class Map;
class LifeForm;

class Entity
{
public:
	Entity(double x, double y);
	//Render the shape of the entity
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	virtual bool refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms) = 0;//Return true if the entity doesn't exist anymore, else false
	//Position<> chunkPosition() const;
	Position<double> getPosition() const { return position; }
	bool pointIsOnThis(Position<> point) const { return shape->pointIsIn(point); }
	~Entity();
protected:
	std::unique_ptr<Renderable> shape;
	Position<double> position;
};

