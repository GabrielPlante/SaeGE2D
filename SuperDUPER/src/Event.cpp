#include "../header/Event.h"
#include "../header/GameLoop.h"
#include "../header/Struct/TextToCommand.h"
#include "../header/EventHandler/ConsoleEventHandler.h"
#include "../header/EventHandler/GameEventHandler.h"

Event::Event()
{
	//Then assign them
	eventToEventType[SDL_QUIT] = "quit";
	eventHandlerStack.emplace_back(std::unique_ptr<EventHandler>{new GameEventHandler{}});
}

void Event::handleEvent(GameLoop* gameLoop) {
	if (event.type == SDL_MOUSEMOTION)
		mouseMoveEvent(gameLoop);
	else {
		auto search = eventToEventType.find(event.type);
		if (search != eventToEventType.end())
			commandList.executeCommand(search->second, gameLoop);
		else {
			HandlerType handle = eventHandlerStack[eventHandlerStack.size() - 1]->handleEvent(&event, gameLoop);
			if (handle == HandlerType::POP)
				eventHandlerStack.pop_back();
			else if (handle == HandlerType::CONSOLE)
				eventHandlerStack.emplace_back(std::unique_ptr<EventHandler>{new ConsoleEventHandler{}});
		}
	}
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
