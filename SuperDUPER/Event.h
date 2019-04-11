#pragma once
#include <SDL.h>
#include "Character.h"
#include <list>
#include "Button.h"
#include "Key.h"
#include <unordered_map>
#include <map>
#include <memory>

/*TODO
 * Pipeline of an event:
 * GameLoop loop on pollEvent while there is event left
 * for each event, gameloop give himself back to Event who treat the event
 */

enum class EventType {QUIT, PLAYER, MOUSE, KEYBOARD, MOUSEMOVE, NONE};

class GameLoop;
class Command;
class Event
{
public:
	Event();
	bool pollEvent() { return SDL_PollEvent(&event); };
	void handleEvent(GameLoop* gameLoop);
	//Internal function to treat keyboard event, return false if the program need to stop
	void keyboardEvent(GameLoop* gameLoop);
	void mouseMoveEvent(GameLoop* gameLoop);
	~Event();
private:
	SDL_Event event;
	const Uint8* state = SDL_GetKeyboardState(NULL);
	//Used to find what command to call for a general event
	std::unordered_map<int, std::shared_ptr<Command>> eventToEventType;
	//Used to find what command to call for a key or mouse button event
	std::map<Key, std::shared_ptr<Command>> keyToEventType;
	std::vector<std::shared_ptr<Command>> eventList;

	//Test to see if this work well, it keep the button the cursor is actually hovering to avoid checking them all
	Button* buttonHovering = nullptr;
};
