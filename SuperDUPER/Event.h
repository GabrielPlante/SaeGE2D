#pragma once
#include <SDL.h>
#include "Player.h"

enum class EventType {QUIT, PLAYER};

class Event
{
public:
	Event();
	bool pollEvent();
	EventType getEventType();
	void playerEvent(Player* player);
	~Event();
private:
	SDL_Event event;
};

