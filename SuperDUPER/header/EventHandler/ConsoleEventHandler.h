#pragma once
#include "EventHandler.h"
class ConsoleEventHandler :
	public EventHandler
{
public:
	ConsoleEventHandler();
	HandlerType handleEvent(SDL_Event* event, GameLoop* gameLoop) const;
	~ConsoleEventHandler();
};

