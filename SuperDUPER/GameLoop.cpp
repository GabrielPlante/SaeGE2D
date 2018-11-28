#include "GameLoop.h"


GameLoop::GameLoop(){
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	gameWindow.clear();//Clear the screen
	//Then put everything in the renderer

	gameWindow.update();//Then print it
	while (event.pollEvent()) {
		if (event.getEventType() == EventType::QUIT)
			return false;
	}
	return true;
	//return timeSinceGameStart < 10000;//Shuting down program after 10 sec
}

GameLoop::~GameLoop()
{
}
