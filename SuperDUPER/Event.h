#pragma once
#include <SDL.h>
#include "Character.h"

enum class EventType {QUIT, PLAYER, MOUSE, NONE};

class Event
{
public:
	Event();
	bool pollEvent();
	EventType getEventType();
	void playerEvent(Character* player);
	void mouseEvent(Character* player, const Camera& camera);
	~Event();
private:
	SDL_Event event;
};

