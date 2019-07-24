#pragma once
#include <list>
#include <memory>
#include <SDL.h>
#include "LifeForm.h"
class Map;
class Camera;
class LifeFormList
{
private:
	typedef std::vector<std::unique_ptr<LifeForm>> LifeForms;
	LifeForms lifeFormList;
public:
	//Default constructor
	LifeFormList(LifeForms lifeFormList = LifeForms{});

	//Refesh the list
	void refreshList(const Map& map, float deltaTime, const std::vector<float>& gameValues);

	//Render the list
	void renderList(SDL_Renderer* renderer, const Camera& camera);
	
	//Get the player, need to be moved out
	LifeForm* getPlayer() { return &(*lifeFormList[0]); }

	//Add a new entity to the list, return the position of the entity
	size_t addLifeForm(std::unique_ptr<LifeForm> lifeForm) { lifeFormList.push_back(std::move(lifeForm)); return lifeFormList.size() - 1; }


	//Used to iterate over the list
	typedef LifeForms::const_iterator const_iterator;
	const_iterator cbegin() const { return lifeFormList.cbegin(); }
	const_iterator cend() const { return lifeFormList.cend(); }
};

