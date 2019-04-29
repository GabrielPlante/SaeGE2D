#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>
#include <array>
#include "Position.h"
#include <vector>


class LifeFormList;
class Map;
class Entity
{
public:
	Entity(float x, float y, int healthPoint, int mass = 0, float bluntDamageMultiplier = 1, float sharpDamageMultiplier = 1);
	//Render the shape of the entity
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	virtual bool refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime) = 0;//Return true if the entity doesn't exist anymore, else false
	//Position<> chunkPosition() const;
	Position<float> getPosition() const { return position; }
	bool pointIsOnThis(Position<> point) const { return shape->pointIsIn(point, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)}); }
	void setMass(int newMass) { mass = newMass; }
	int getMass() const { return mass; }
	void takeBluntDamage(int amount);
	void takeSharpDamage(int amount);
	~Entity();
protected:
	std::unique_ptr<Renderable> shape;
	Position<float> position;
	int mass;
	int healthPoint;
	float bluntDamageMultiplier;//Between 0 and 1, 0 = full blunt damage resisting, 1 = non blunt damage resistance
	float sharpDamageMultiplier;
};

