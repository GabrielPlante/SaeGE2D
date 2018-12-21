#include "GameLoop.h"
constexpr int SCREEN_WIDTH{ 1200 };
constexpr int SCREEH_HEIGHT{ 600 };

GameLoop::GameLoop()
	:map{}, player{ 100, 100, Color(0, 0, 255) }, gameWindow{ SCREEN_WIDTH, SCREEH_HEIGHT }
{
	//test
	entities.emplace_back(std::unique_ptr<Entity>{new Character(400, 400, Color(128, 128, 128))});
	entities.emplace_back(std::unique_ptr<Entity>{new Character(600, 400, Color(128, 128, 128))});
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//First, see if there is any input from the user
	if (!handleEvent(event))
		return false;

	refreshEntities();

	gameWindow.clear();//Then clear the screen
	//Then put everything in the renderer

	map.render(gameWindow.getRenderer(), gameWindow.getCamera());

	renderEntities(gameWindow.getRenderer(), gameWindow.getCamera());

	gameWindow.update();//Then print it
	return true;
}

bool GameLoop::handleEvent(Event& event) {
	while (event.pollEvent()) {
		if (event.getEventType() == EventType::QUIT)
			return false;
		else if (event.getEventType() == EventType::MOUSE) {
			event.mouseEvent(&player, gameWindow.getCamera());
		}
	}
	return true;
}

void GameLoop::refreshEntities() {
	int entitiesSize = entities.size();
	if (entitiesSize) {
		std::unique_ptr<Entity>* entitiesPtr = &entities[0];
		for (int i = 0; i != entitiesSize; i++) {
			entitiesPtr[i]->refresh();
		}
	}
	player.refresh();
}

void GameLoop::renderEntities(SDL_Renderer* renderer, Camera& camera) {
	int entitiesSize = entities.size();
	if (entitiesSize) {
		std::unique_ptr<Entity>* entitiesPtr = &entities[0];
		for (int i = 0; i != entitiesSize; i++) {
			entitiesPtr[i]->render(renderer, camera);//Put all the entities
		}
	}
	player.render(renderer, camera);//Put the player last so he is above everything else
}

GameLoop::~GameLoop()
{
}
