#pragma once
#include <list>
#include <memory>
#include <SDL.h>
#include "Entity.h"
class Map;
class Camera;
class EntityList
{
private:
	typedef std::vector<std::unique_ptr<Entity>> Entities;
	Entities entityList;
public:
	//Default constructor
	EntityList(Entities entitiesList = Entities{});

	//Refesh the list
	void refreshList(const Map& map, float deltaTime, const std::vector<float>& gameValues);

	//Render the list
	void renderList(SDL_Renderer* renderer, const Camera& camera);
	
	//Get the player, need to be moved out
	Entity* getPlayer() { return &(*entityList[0]); }

	//Add a new entity to the list, return the position of the entity
	size_t addEntity(std::unique_ptr<Entity> entities) { entityList.push_back(std::move(entities)); return entityList.size() - 1; }


	//Used to iterate over the list
	typedef Entities::const_iterator const_iterator;
	const_iterator cbegin() const { return entityList.cbegin(); }
	const_iterator cend() const { return entityList.cend(); }
};

