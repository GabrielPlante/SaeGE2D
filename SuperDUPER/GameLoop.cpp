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


	//Create the player
	player = std::unique_ptr<LifeForm>{new Character{ 100, 0, Color(0, 0, 255) }};
	player->setVisionRendering(true);
	//test
	entityList.addEntity(std::unique_ptr<LifeForm>{new Character{ 400, 400, Color(128, 128, 128) }});
	//lifeForms.emplace_back(std::unique_ptr<LifeForm>{new Character(600, 400, Color(128, 128, 128))});

	player->takeWeaponInHand(std::unique_ptr<Weapon> {new Weapon{ "Basic Bow", 100, 100, 1000, 0.5, 1,
		std::unique_ptr<WeaponAttack>{new BasicArrow{0, 1, Position<float>{0, 0}, 300, 1000, static_cast<float>(0.2), 1, (getPlayer()->getId())}} } });

	//Test
	std::unique_ptr<Button> textTest = std::unique_ptr<Button>{ new Button{Color{0, 0, 180, 180}, "Une phrase random xDDDzqfj", gameWindow.getRenderer(), Position<>{50, 50}, Font{50} } };
	buttonList.push_back(std::move(textTest));

	timeSinceGameStart = SDL_GetTicks();
}

//For some reasons, this function doesn't work if it's inlined
LifeForm* GameLoop::getPlayer() { return player.get(); }

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//First, see if there is any input from the user
	handleEvent(event);

	//Refresh all the entity the game have
	refreshEntities();

	//Set the camera position at the middle of the screen
	gameWindow.getCamera().setPosition(Position<>{static_cast<long>(entityList.getPlayer()->getPosition().x)-SCREEN_WIDTH/2, static_cast<long>(entityList.getPlayer()->getPosition().y)-SCREEH_HEIGHT/2});

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
