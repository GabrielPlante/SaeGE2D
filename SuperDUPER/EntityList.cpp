#include "EntityList.h"



EntityList::EntityList(Entities entityList)
	:entityList{ std::move(entityList) }
{
}

void EntityList::refreshList(const Map& map, float deltaTime, const std::vector<float>& gameValues) {
	auto it = entityList.begin();
	while (it != entityList.end()) {
		if ((**it).refresh(map, (*this), deltaTime, gameValues))
			it = entityList.erase(it);
		else
			it++;
	}
}

void EntityList::renderList(SDL_Renderer* renderer, const Camera& camera) {
	for (auto it = entityList.begin(); it != entityList.end(); it++) {
		//Hide the entities the player do not see
		//if (getPlayer()->isInSight((**it).getPosition()) || &(**it) == getPlayer())//Need to find something else, maybe something at camera level
			(**it).render(renderer, camera);
	}
}
