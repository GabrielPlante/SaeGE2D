#pragma once
#include <SDL.h>

enum class EventType {QUIT};

class Event
{
public:
	Event();
	bool pollEvent();
	EventType getEventType();
	~Event();
private:
	SDL_Event event;
};

