#include "GameLoop.h"
#include "Weapon.h"
#include "BasicArrow.h"
constexpr int SCREEN_WIDTH{ 1200 };
constexpr int SCREEH_HEIGHT{ 600 };

GameLoop::GameLoop()
	:map{}, gameWindow{ SCREEN_WIDTH, SCREEH_HEIGHT }, console{ Rectangle{50, 50, 800, 500} }
{
	//The game values
	float gravity = 1;
	gameValues.push_back(gravity);


	//Test
	std::unique_ptr<Button> textTest = std::unique_ptr<Button>{ new Button{Color{0, 0, 180, 180}, "Une phrase random xDDDzqfj", gameWindow.getRenderer(), Position<>{50, 50}, Font{50} } };
	buttonList.push_back(std::move(textTest));

	timeSinceGameStart = SDL_GetTicks();
}

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//First, see if there is any input from the user
	handleEvent(event);

	//Refresh all the entity the game have
	refreshEntities();

	//Clear the screen
	gameWindow.clear();

	//Render the map first
	map.render(gameWindow.getRenderer(), gameWindow.getCamera());

	//Render the entities above the map
	renderEntities(gameWindow.getRenderer(), gameWindow.getCamera());
	
	//Render the buttons above the entities
	renderButtons(gameWindow.getRenderer());

	//Render the console above everything else
	console.render(gameWindow.getRenderer());

	gameWindow.update();//Then print it
	return keepGoing;
}

void GameLoop::handleEvent(Event& event) {
	while (event.pollEvent()) {
		event.handleEvent(this);
	}
}

void GameLoop::refreshEntities() {
	float deltaTime = static_cast<float>(static_cast<double>(gameClock.resetTime()) / (1000 * 1000));
	entityList.refreshList(map, deltaTime, gameValues);
}

void GameLoop::renderEntities(SDL_Renderer* renderer, Camera& camera) {
	entityList.renderList(renderer, camera);
}

void GameLoop::renderButtons(SDL_Renderer* renderer) {
	for (auto it = buttonList.begin(); it != buttonList.end(); it++)
		(**it).render(renderer);
}
