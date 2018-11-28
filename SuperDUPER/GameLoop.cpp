#include "GameLoop.h"

GameLoop::GameLoop(){
	player = std::shared_ptr<Player>{ new Player(100, 100) };
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//First, see if there is any input from the user
	while (event.pollEvent()) {
		if (event.getEventType() == EventType::QUIT)
			return false;
		else if (event.getEventType() == EventType::PLAYER) {
			event.playerEvent(&(*player));
		}
	}

	//Then refresh everything that has to be
	for (auto it = entities.begin(); it != entities.end(); it++) {
		(**it).refresh();
	}
	player->refresh();

	gameWindow.clear();//Then clear the screen
	//Then put everything in the renderer

	for (auto it = entities.begin(); it != entities.end(); it++) {
		(**it).render(gameWindow.getRenderer());//Put all the entities
	}
	player->render(gameWindow.getRenderer());//Put the player last so he is above everything else

	gameWindow.update();//Then print it
	return true;
	//return timeSinceGameStart < 10000;//Shuting down program after 10 sec
}

GameLoop::~GameLoop()
{
}
