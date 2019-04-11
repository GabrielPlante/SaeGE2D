#include "Event.h"
#include "GameLoop.h"

Event::Event()
{
	//Then assign them
	eventToEventType[SDL_QUIT] = "quit";
	keyToEventType[SDLK_ESCAPE] = "quit";
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_LEFT)] = "pl_attack";
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_RIGHT)] = "pl_move";
}

void Event::handleEvent(GameLoop* gameLoop) {
	if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
		keyboardEvent(gameLoop);
	else if (event.type == SDL_MOUSEMOTION)
		mouseMoveEvent(gameLoop);
	else {
		auto search = eventToEventType.find(event.type);
		if (search != eventToEventType.end())
			commandList.executeCommand(search->second, gameLoop);
	}
}

//It's called keyboard event but it's mouse and keyboard event
void Event::keyboardEvent(GameLoop* gameLoop) {
	//Is it a mouse or keyboard event
	auto search = event.type == SDL_KEYDOWN ? keyToEventType.find(event.key.keysym.sym) : keyToEventType.find(event.button.button);
	//If nothing is found we exit early
	if (search == keyToEventType.end())
		return;
	//Those function need special arguments
	else if (search->second == "pl_attack" || search->second == "pl_move") {
		commandList.executeCommand(search->second, gameLoop, std::vector<float>{ static_cast<float>(event.motion.x), static_cast<float>(event.motion.y) });
	}
	//Generic function that can be treated with only gameloop
	else
		commandList.executeCommand(search->second, gameLoop);
}

void Event::mouseMoveEvent(GameLoop* gameLoop) {
	//If at the last mouse movement the mouse was on a button
	if (buttonHovering) {
		//Check if the mouse is still on the button
		if (!buttonHovering->checkIfHovering(Position<>{static_cast<long>(event.motion.x), static_cast<long>(event.motion.y)}))
			buttonHovering = nullptr;
	}
	//Else we check every button again
	else {
		for (auto it = gameLoop->getButtonList()->begin(); it != gameLoop->getButtonList()->end(); it++) {
			if ((**it).checkIfHovering(Position<>{static_cast<long>(event.motion.x), static_cast<long>(event.motion.y)})) {
				buttonHovering = &(**it);
				break;
			}
		}
	}
}

Event::~Event()
{
}
