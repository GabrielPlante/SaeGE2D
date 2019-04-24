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
	LifeFormList(LifeForms lifeFormList = LifeForms{});
	void refreshList(const Map& map, float deltaTime);
	void renderList(SDL_Renderer* renderer, const Camera& camera);
	LifeForm* getPlayer() { return &(*lifeFormList[0]); }
	void addLifeForm(std::unique_ptr<LifeForm> lifeForm) { lifeFormList.push_back(std::move(lifeForm)); }
	typedef LifeForms::const_iterator const_iterator;
	const_iterator cbegin() const { return lifeFormList.cbegin(); }
	const_iterator cend() const { return lifeFormList.cend(); }
	~LifeFormList();
};

