#include "GameLoop.h"
constexpr int SCREEN_WIDTH{ 1200 };
constexpr int SCREEH_HEIGHT{ 600 };

GameLoop::GameLoop()
	:map{}, player{ 100, 100, Color(0, 0, 255) }, gameWindow{ SCREEN_WIDTH, SCREEH_HEIGHT }
{
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//First, see if there is any input from the user
	while (event.pollEvent()) {
		if (event.getEventType() == EventType::QUIT)
			return false;
		else if (event.getEventType() == EventType::PLAYER) {
			event.playerEvent(&player);
		}
	}


	//Then refresh everything that has to be
	int entitiesSize = entities.size();
	if (entitiesSize) {
		Entity* entitiesPtr = &entities[0];
		for (int i = 0; i != entitiesSize; i++) {
			entitiesPtr[i].refresh();
		}
	}
	player.refresh();

	gameWindow.clear();//Then clear the screen
	//Then put everything in the renderer

	//First, render the map (background)
	map.render(gameWindow.getRenderer(), gameWindow.getViewport());

	if (entitiesSize) {
		Entity* entitiesPtr = &entities[0];
		for (int i = 0; i != entitiesSize; i++) {
			entitiesPtr[i].render(gameWindow.getRenderer(), gameWindow.getViewport());//Put all the entities
		}
	}
	player.render(gameWindow.getRenderer(), gameWindow.getViewport());//Put the player last so he is above everything else

	gameWindow.update();//Then print it
	return true;
	//return timeSinceGameStart < 10000;//Shuting down program after 10 sec
}

GameLoop::~GameLoop()
{
}
