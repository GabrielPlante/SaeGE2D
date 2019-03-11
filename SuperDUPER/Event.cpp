#include "Event.h"

Event::Event()
{
	eventToEventType[SDL_QUIT] = EventType::QUIT;
	eventToEventType[SDL_MOUSEBUTTONDOWN] = EventType::MOUSE;
	eventToEventType[SDL_KEYDOWN] = EventType::KEYBOARD;
	eventToEventType[SDL_MOUSEMOTION] = EventType::MOUSEMOVE;
}

EventType Event::getEventType() {
	auto search = eventToEventType.find(event.type);
	return search == eventToEventType.end() ? EventType::NONE : search->second;
	/*if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
		return EventType::QUIT;
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		return EventType::MOUSE;
	else if (event.type == SDL_KEYDOWN)
		return EventType::KEYBOARD;
	else if (event.type == SDL_MOUSEMOTION)
		return EventType::MOUSEMOVE;
	return EventType::NONE;*/
}

void Event::playerEvent(LifeForm* player) const {
}

void Event::mouseEvent(LifeForm* player, const Camera& camera, const std::list<std::unique_ptr<LifeForm>>& lifeFormsList) const {
	if (event.type == SDL_MOUSEBUTTONDOWN/* && event.button.button == SDL_BUTTON_RIGHT*/) {
		//First get the mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);//Get the position of the mouse
		//Convert it in absolute position
		Position<> absolutePosition{ camera.relativeToAbsolute(x, y) };//Convert x & y to absolute position
		//If it's a left click, attack (temporary hard coded solution)
		if (event.button.button == SDL_BUTTON_LEFT)
			player->attack(absolutePosition);
		//Then deal with right click, to see if the player clicked on an entity
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

void Event::mouseMoveEvent(const std::vector<std::unique_ptr<Button>>& buttonList) const {
	int x, y;
	SDL_GetMouseState(&x, &y);
	for (auto it = buttonList.begin(); it != buttonList.end(); it++) {
		(**it).checkIfHovering(Position<>{static_cast<long>(x), static_cast<long>(y)});
	}
}

void Event::keyboardEvent(LifeForm* player) {
	keyActionMap.executeAction(event.key.keysym.sym, player);
}

Event::~Event()
{
}
