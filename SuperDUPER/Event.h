#pragma once
#include <SDL.h>
#include "Character.h"
#include <list>
#include "KeyActionMap.h"
#include "Button.h"

enum class EventType {QUIT, PLAYER, MOUSE, KEYBOARD, MOUSEMOVE, NONE};

class Event
{
public:
	Event();
	bool pollEvent() { return SDL_PollEvent(&event); };
	EventType getEventType();
	void playerEvent(LifeForm* player) const;
	void mouseEvent(LifeForm* player, const Camera& camera, const std::list<std::unique_ptr<LifeForm>>& lifeFormsList) const;
	void mouseMoveEvent(const std::vector<std::unique_ptr<Button>>& buttonList) const;
	void keyboardEvent(LifeForm* player);
	~Event();
private:
	SDL_Event event;
	const Uint8* state = SDL_GetKeyboardState(NULL);
	KeyActionMap keyActionMap;
};

