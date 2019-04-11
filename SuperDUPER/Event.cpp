#include "Event.h"
#include "Quit.h"
#include "Attack.h"
#include "Move.h"
#include "GameLoop.h"

Event::Event()
{
	//First create all the command
	eventList.push_back(std::shared_ptr<Command>{new Quit()});
	eventList.push_back(std::shared_ptr<Command>{new Attack()});
	eventList.push_back(std::shared_ptr<Command>{new Move()});
	//Then assign them
	eventToEventType[SDL_QUIT] = eventList[0];
	keyToEventType[SDLK_ESCAPE] = eventList[0];
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_LEFT)] = eventList[1];
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_RIGHT)] = eventList[2];
}

void Event::handleEvent(GameLoop* gameLoop) {
	if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
		keyboardEvent(gameLoop);
	else if (event.type == SDL_MOUSEMOTION)
		mouseMoveEvent(gameLoop);
	else {
		auto search = eventToEventType.find(event.type);
		if (search != eventToEventType.end())
			search->second->execute(gameLoop);
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
	else if (search->second->getName() == "pl_attack" || search->second->getName() == "pl_move") {
		search->second->execute(gameLoop, std::vector<float>{static_cast<float>(event.motion.x), static_cast<float>(event.motion.y)});
	}
	//Generic function that can be treated with only gameloop
	else
		search->second->execute(gameLoop);
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
