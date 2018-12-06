#pragma once
#include <SDL.h>
#include "Character.h"

enum class EventType {QUIT, PLAYER, NONE};

class Event
{
public:
	Event();
	bool pollEvent();
	EventType getEventType();
	void playerEvent(Character* player);
	~Event();
private:
	SDL_Event event;
};

