#pragma once
#include <vector>
#include <memory>
#include <SDL.h>
#include "LifeForm.h"
class Map;
class Camera;
class LifeFormList
{
public:
	LifeFormList(std::vector<std::unique_ptr<LifeForm>> lifeFormList = std::vector<std::unique_ptr<LifeForm>>{});
	void refreshList(const Map& map, float deltaTime);
	void renderList(SDL_Renderer* renderer, const Camera& camera);
	const std::vector<std::unique_ptr<LifeForm>>& getLifeFormList() const { return lifeFormList; }
	LifeForm* getPlayer() { return &(*lifeFormList[0]); }
	void addLifeForm(std::unique_ptr<LifeForm> lifeForm) { lifeFormList.push_back(std::move(lifeForm)); }
	~LifeFormList();
private:
	std::vector<std::unique_ptr<LifeForm>> lifeFormList;
};

