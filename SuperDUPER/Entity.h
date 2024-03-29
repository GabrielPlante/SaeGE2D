#pragma once
#include <SDL.h>
#include "Renderable.h"
#include <memory>
#include <array>
#include "Position.h"
#include <vector>
#include "Damage.h"

/*
TODO: Change this class so it's the base class and the only class representing an entity in the game engine
It need to have a system so each can be rendered on a screen or not. It also need to have a refresh.
Maybe do three functions called in this order: Command(Input); Refresh; Render
*/

class EntityList;
class Map;
class Entity
{
protected:
	const unsigned long id;
	static unsigned long idCount;//Each entity has a unique ID
	std::unique_ptr<Renderable> shape;
	Position<float> position;
	int mass;
	int healthPoint;
	float bluntDamageMultiplier;//Between 0 and 1, 0 = full blunt damage resisting, 1 = non blunt damage resistance
	float sharpDamageMultiplier;
	


public:
	//Constructor
	Entity(float x, float y, int healthPoint, int mass = 0, float bluntDamageMultiplier = 1, float sharpDamageMultiplier = 1);

	//Render the shape of the entity
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;

	//Refresh the entity
	virtual bool refresh(const Map& map, const EntityList& lifeForms, float deltaTime, const std::vector<float>& gameValues) = 0;//Return true if the entity doesn't exist anymore, else false

	//Get the position of the entity
	Position<float> getPosition() const { return position; }

	//Check if a point is on the entity
	bool pointIsOnThis(Position<> point) const { return shape->pointIsIn(point, Position<>{static_cast<long>(position.x), static_cast<long>(position.y)}); }

	//Set the mass of the entity
	void setMass(int newMass) { mass = newMass; }

	//Get the mass of the entity
	int getMass() const { return mass; }

	//Return true if the entity is still alive after the damage input
	virtual bool takeDamage(const Damage& damage) = 0;

	virtual bool isInSight(const Position<float>& otherPos) const = 0;

	//Return the id of the entity
	unsigned long getId() const { return id; }

	//Compare two entity with their id
	bool operator==(const Entity& other) const { return id == other.getId(); }
	bool operator!=(const Entity& other) const { return id != other.getId(); }
};

