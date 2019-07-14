#pragma once
#include <SDL.h>
#include "CommandList.h"

enum class HandlerType { NONE, POP, GAME, CONSOLE };

class GameLoop;
class EventHandler
{
public:
	EventHandler();
	virtual HandlerType handleEvent(SDL_Event* event, GameLoop* gameLoop) const = 0;
	const CommandList& getCommandList() const { return commandList; }
	~EventHandler();
private:
	static CommandList commandList;
};

