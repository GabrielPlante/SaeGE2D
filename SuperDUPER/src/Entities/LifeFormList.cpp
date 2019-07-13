#include "../../header/Entities/LifeFormList.h"
#include "../../header/Entities/LifeForm.h"



LifeFormList::LifeFormList(LifeForms lifeFormList)
	:lifeFormList{ std::move(lifeFormList) }
{
}

void LifeFormList::refreshList(const Map& map, float deltaTime, const std::vector<float>& gameValues) {
	auto it = lifeFormList.begin();
	while (it != lifeFormList.end()) {
		if ((**it).refresh(map, (*this), deltaTime, gameValues))
			it = lifeFormList.erase(it);
		else
			it++;
	}
}

void LifeFormList::renderList(SDL_Renderer* renderer, const Camera& camera) {
	for (auto it = lifeFormList.begin(); it != lifeFormList.end(); it++) {
		if (getPlayer()->isInSight((**it).getPosition()) || &(**it) == getPlayer())
			(**it).render(renderer, camera);
	}
}

LifeFormList::~LifeFormList()
{
}
