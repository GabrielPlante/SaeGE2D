#pragma once
#include "EventHandler.h"
#include <map>
#include "Key.h"
#include <string.h>
class GameEventHandler :
	public EventHandler
{
public:
	GameEventHandler();
	HandlerType handleEvent(SDL_Event* event, GameLoop* gameLoop) const;
	~GameEventHandler();
private:
	static std::map<Key, std::string> keyToEventType;
	//Used to find what command to call for a key or mouse button event
	HandlerType keyboardEvent(SDL_Event* event, GameLoop* gameLoop) const;
};

