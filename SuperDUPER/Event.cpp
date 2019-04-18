#include "Event.h"
#include "GameLoop.h"
#include "TextToCommand.h"

Event::Event()
{
	//Then assign them
	eventToEventType[SDL_QUIT] = "quit";
	keyToEventType[SDLK_ESCAPE] = "quit";
	keyToEventType[SDLK_a] = "co_open";
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_LEFT)] = "pl_attack";
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_RIGHT)] = "pl_move";
	keyToEventType[SDLK_SPACE] = "pl_stop";
}

void Event::handleEvent(GameLoop* gameLoop) {
	if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
		keyboardEvent(gameLoop);
	else if (event.type == SDL_MOUSEMOTION)
		mouseMoveEvent(gameLoop);
	else if (event.type == SDL_TEXTINPUT && gameLoop->getConsole()->isOpened())
		gameLoop->getConsole()->addText(event.text.text);
	else {
		auto search = eventToEventType.find(event.type);
		if (search != eventToEventType.end())
			commandList.executeCommand(search->second, gameLoop);
	}
}

//It's called keyboard event but it's mouse and keyboard event
void Event::keyboardEvent(GameLoop* gameLoop) {
	if (event.type == SDL_KEYDOWN && gameLoop->getConsole()->isOpened()) {
		//Handle closing the console
		if (event.key.keysym.sym == SDLK_ESCAPE)
			gameLoop->getConsole()->close();
		//Handle backspace
		else if (event.key.keysym.sym == SDLK_BACKSPACE)
			gameLoop->getConsole()->popText();
		//Handle paste
		else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
			gameLoop->getConsole()->addText(SDL_GetClipboardText());
		//Handle copy
		else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
			SDL_SetClipboardText(gameLoop->getConsole()->getInputText().c_str());
		else if (event.key.keysym.sym == SDLK_RETURN) {
			TextToCommand textToCommand{ gameLoop->getConsole()->getCommand() };
			commandList.executeCommand(textToCommand.getCommandName(), gameLoop, textToCommand.getArgs());
			gameLoop->getConsole()->clear();
		}
		//We dont want the event to affect the game
		return;
	}
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
