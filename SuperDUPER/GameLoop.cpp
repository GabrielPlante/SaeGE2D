#include "GameLoop.h"



GameLoop::GameLoop(){
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	gameWindow.clear();
	gameWindow.update();
	while (event.pollEvent()) {
		if (event.getEventType() == EventType::QUIT)
			return false;
	}
	return timeSinceGameStart < 10000;//Shuting down program after 10 sec
}

GameLoop::~GameLoop()
{
}
