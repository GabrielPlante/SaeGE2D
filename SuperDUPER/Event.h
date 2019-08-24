#pragma once
#include <SDL.h>
#include <list>
#include "Button.h"
#include "Key.h"
#include <unordered_map>
#include <map>
#include <memory>
#include "CommandList.h"
#include "EventHandler.h"

/*TODO
 * Pipeline of an event:
 * GameLoop loop on pollEvent while there is event left
 * for each event, gameloop give himself back to Event who treat the event
 */

class GameLoop;
class Command;
class Event
{
public:
	Event();
	bool pollEvent() { return SDL_PollEvent(&event); };
	void handleEvent(GameLoop* gameLoop);
	//Internal function to treat keyboard event, return false if the program need to stop
	void mouseMoveEvent(GameLoop* gameLoop);
	~Event();
private:
	SDL_Event event;
	const Uint8* state = SDL_GetKeyboardState(NULL);
	//Used to find what command to call for a general event
	std::unordered_map<int, std::string> eventToEventType;

	CommandList commandList;

	std::vector<std::unique_ptr<EventHandler>> eventHandlerStack;

	//Test to see if this work well, it keep the button the cursor is actually hovering to avoid checking them all
	Button* buttonHovering = nullptr;
};
