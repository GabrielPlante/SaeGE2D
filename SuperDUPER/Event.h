#pragma once
#include <SDL.h>
#include "Character.h"

enum class EventType {QUIT, PLAYER, MOUSE, NONE};

class Event
{
public:
	Event();
	bool pollEvent() { return SDL_PollEvent(&event); };
	EventType getEventType();
	void playerEvent(Character* player);
	void mouseEvent(Character* player, const Camera& camera, const std::vector<std::unique_ptr<Entity>>& entitiesList);
	~Event();
private:
	SDL_Event event;
};

