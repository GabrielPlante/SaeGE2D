#include "Event.h"

Event::Event()
{
}

EventType Event::getEventType() {
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
		return EventType::QUIT;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		return EventType::MOUSE;
	return EventType::NONE;
}

void Event::playerEvent(Character* player) {
}

void Event::mouseEvent(Character* player, const Camera& camera, const std::vector<std::unique_ptr<Entity>>& entitiesList) {
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		int x, y;
		SDL_GetMouseState(&x, &y);//Get the position of the mouse
		Position<> absolutePosition{ camera.relativeToAbsolute(x, y) };//Convert x & y to absolute position
		bool clickedOnEntity = false;
		for (auto it = entitiesList.begin(); it != entitiesList.end(); it++) {
			if ((**it).pointIsOnThis(absolutePosition) && player->isInSight((**it).getPosition())) {
				player->setDestination(&(**it));
				clickedOnEntity = true;
			}
		}
		if (!clickedOnEntity)
			player->setDestination(Position<>(absolutePosition.x, absolutePosition.y));
	}
}

Event::~Event()
{
}
