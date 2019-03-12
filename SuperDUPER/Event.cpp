#include "Event.h"

Event::Event()
{
	eventToEventType[SDL_QUIT] = EventType::QUIT;
	eventToEventType[SDL_MOUSEBUTTONDOWN] = EventType::MOUSE;
	eventToEventType[SDL_KEYDOWN] = EventType::KEYBOARD;
	eventToEventType[SDL_MOUSEMOTION] = EventType::MOUSEMOVE;

	keyToEventType[SDLK_ESCAPE] = EventType::QUIT;
}

EventType Event::getEventType() {
	auto search = eventToEventType.find(event.type);
	if (search == eventToEventType.end())
		return EventType::NONE;
	if (search->second == EventType::KEYBOARD)
		return keyboardEvent();
	return search->second;
}

EventType Event::keyboardEvent() {
	auto search = keyToEventType.find(event.key.keysym.sym);
	return search == keyToEventType.end() ? EventType::NONE : search->second;
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
	for (auto it = buttonList.begin(); it != buttonList.end(); it++) {
		(**it).checkIfHovering(Position<>{static_cast<long>(event.motion.x), static_cast<long>(event.motion.y)});
	}
}

Event::~Event()
{
}
