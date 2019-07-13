#include "../../header/EventHandler/ConsoleEventHandler.h"
#include "../../header/GameLoop.h"



ConsoleEventHandler::ConsoleEventHandler()
{
}

HandlerType ConsoleEventHandler::handleEvent(SDL_Event* event, GameLoop* gameLoop) const {
	if (event->type == SDL_KEYDOWN) {
		//Handle closing the console
		if (event->key.keysym.sym == SDLK_ESCAPE) {
			gameLoop->getConsole()->close();
			return HandlerType::POP;
		}
		//Handle backspace
		else if (event->key.keysym.sym == SDLK_BACKSPACE)
			gameLoop->getConsole()->popText();
		//Handle paste
		else if (event->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
			gameLoop->getConsole()->pushBackText(SDL_GetClipboardText());
		//Handle copy
		else if (event->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
			SDL_SetClipboardText(gameLoop->getConsole()->getInputText().c_str());
		else if (event->key.keysym.sym == SDLK_RETURN) {
			gameLoop->getConsole()->enterCommand(getCommandList(), gameLoop);
		}
	}
	else if (event->type == SDL_TEXTINPUT)
		gameLoop->getConsole()->pushBackText(event->text.text);
	return HandlerType::NONE;

}

ConsoleEventHandler::~ConsoleEventHandler()
{
}
