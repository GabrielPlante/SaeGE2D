#include "GameEventHandler.h"
#include "Position.h"
#include "GameLoop.h"

std::map<Key, std::string> GameEventHandler::keyToEventType;

GameEventHandler::GameEventHandler()
{
	if (!keyToEventType.size()) {
		keyToEventType[SDLK_ESCAPE] = "quit";
		keyToEventType[SDLK_a] = "co_open";
		keyToEventType[static_cast<Uint8>(SDL_BUTTON_LEFT)] = "pl_attack";
		keyToEventType[static_cast<Uint8>(SDL_BUTTON_RIGHT)] = "pl_move";
		keyToEventType[SDLK_SPACE] = "pl_stop";
	}
}


HandlerType GameEventHandler::handleEvent(SDL_Event* event, GameLoop* gameLoop) const {
	//if (event->type == SDL_KEYDOWN || event->type == SDL_MOUSEBUTTONDOWN)
	return keyboardEvent(event, gameLoop);
}

HandlerType GameEventHandler::keyboardEvent(SDL_Event* event, GameLoop* gameLoop) const {
	//Is it a mouse or keyboard event
	auto search = event->type == SDL_KEYDOWN ? keyToEventType.find(event->key.keysym.sym) : keyToEventType.find(event->button.button);
	//If nothing is found we exit early
	if (search == keyToEventType.end())
		return HandlerType::NONE;
	//Those function need special arguments
	else if (search->second == "pl_attack" || search->second == "pl_move") {
		Position<> absPosOfCursor{ gameLoop->getCamera()->relativeToAbsolute(event->motion.x, event->motion.y) };
		getCommandList().executeCommand(search->second, gameLoop, std::vector<float>{ static_cast<float>(absPosOfCursor.x), static_cast<float>(absPosOfCursor.y) });
	}
	//Generic function that can be treated with only gameloop
	else
		getCommandList().executeCommand(search->second, gameLoop);
	if (gameLoop->getConsole()->isOpened())
		return HandlerType::CONSOLE;
	return HandlerType::NONE;
}

GameEventHandler::~GameEventHandler()
{
}
