#include "GameLoop.h"
#include "Circle.h"
#include "Rect.h"


GameLoop::GameLoop(){
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//Circle circleTest{ 400, 400, 4, Color(255, 255, 255) };
	Rect rectTest{ 400, 400, 4, 4, Color(255, 255, 255) };
	gameWindow.clear();
	//circleTest.render(gameWindow.getRenderer());
	rectTest.render(gameWindow.getRenderer());
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
