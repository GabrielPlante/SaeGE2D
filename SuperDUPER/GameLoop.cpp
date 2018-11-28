#include "GameLoop.h"


GameLoop::GameLoop(){
	std::unique_ptr<Entity> player{ new Player(100, 100) };
	entities.push_back(std::move(player));
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	gameWindow.clear();//Clear the screen
	//Then put everything in the renderer

	for (auto it = entities.begin(); it != entities.end(); it++) {
		(**it).render(gameWindow.getRenderer());//Put all the entities
	}

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
