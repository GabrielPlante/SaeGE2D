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

void Event::playerEvent(LifeForm* player) {
}

void Event::mouseEvent(LifeForm* player, const Camera& camera, const std::list<std::unique_ptr<LifeForm>>& lifeFormsList) {
	if (event.type == SDL_MOUSEBUTTONDOWN/* && event.button.button == SDL_BUTTON_RIGHT*/) {
		int x, y;
		SDL_GetMouseState(&x, &y);//Get the position of the mouse
		Position<> absolutePosition{ camera.relativeToAbsolute(x, y) };//Convert x & y to absolute position
		if (event.button.button == SDL_BUTTON_LEFT)
			player->attack(absolutePosition);
		bool clickedOnEntity = false;
		for (auto it = lifeFormsList.begin(); it != lifeFormsList.end(); it++) {
			if ((**it).pointIsOnThis(absolutePosition) && player->isInSight((**it).getPosition())) {
				if (event.button.button == SDL_BUTTON_RIGHT) {
					player->setDestination(&(**it));
				}
				clickedOnEntity = true;
				break;
			}
		}
		if (!clickedOnEntity && event.button.button == SDL_BUTTON_RIGHT) {
			player->setDestination(Position<>(absolutePosition.x, absolutePosition.y));
		}
	}
}

Event::~Event()
{
}
