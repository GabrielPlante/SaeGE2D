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
	void playerEvent(LifeForm* player);
	void mouseEvent(LifeForm* player, const Camera& camera, const std::vector<std::unique_ptr<LifeForm>>& lifeFormsList);
	~Event();
private:
	SDL_Event event;
	const Uint8* state = SDL_GetKeyboardState(NULL);
};

