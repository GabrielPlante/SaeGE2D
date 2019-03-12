#pragma once
#include <SDL.h>
#include "Character.h"
#include <list>
#include "Button.h"
#include "Key.h"
#include <unordered_map>
#include <map>

/*TODO
 * Pipeline of an event:
 * GameLoop loop on pollEvent while it's != than NONE
 * Internally the Event class check if the event is and react to it, if it's a keyboard or mouse event another function is needed to treat it
 * GameLoop call the right function with the right argument each loop depending on what pollEvent returned
 * The function execute it's task
 */

enum class EventType {QUIT, PLAYER, MOUSE, KEYBOARD, MOUSEMOVE, NONE};

class Event
{
public:
	Event();
	bool pollEvent() { return SDL_PollEvent(&event); };
	EventType getEventType();
	//Internal function to treat keyboard event
	EventType keyboardEvent();
	void playerEvent(LifeForm* player) const;
	void mouseEvent(LifeForm* player, const Camera& camera, const std::list<std::unique_ptr<LifeForm>>& lifeFormsList) const;
	void mouseMoveEvent(const std::vector<std::unique_ptr<Button>>& buttonList) const;
	~Event();
private:
	SDL_Event event;
	const Uint8* state = SDL_GetKeyboardState(NULL);
	//This map is used to transform an SDL_Event into an EventType
	std::unordered_map<int, EventType> eventToEventType;
	//This one is used when the eventType found with the map above is related to a key, so we need more information (what key, what does it do)
	std::map<Key, EventType> keyToEventType;
};
