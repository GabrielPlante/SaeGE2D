#include "GameLoop.h"
#include "Weapon.h"
#include "BasicArrow.h"
constexpr int SCREEN_WIDTH{ 1200 };
constexpr int SCREEH_HEIGHT{ 600 };

GameLoop::GameLoop()
	:map{}, gameWindow{ SCREEN_WIDTH, SCREEH_HEIGHT }, console{ Rectangle{700, 50, 400, 500} }
{
	//Create the player
	lifeFormList.addLifeForm(std::unique_ptr<LifeForm>{new Character{ 100, 0, Color(0, 0, 255) }});
	//test
	lifeFormList.addLifeForm(std::unique_ptr<LifeForm>{new Character{ 400, 400, Color(128, 128, 128) }});
	//lifeForms.emplace_back(std::unique_ptr<LifeForm>{new Character(600, 400, Color(128, 128, 128))});

	lifeFormList.getPlayer()->takeWeaponInHand(std::unique_ptr<Weapon> {new Weapon{ "Basic Bow", 100, 100, 1000, 0.5, 1,
		std::unique_ptr<WeaponAttack>{new BasicArrow{0, 1, Position<float>{0, 0}, 300, 1000, 0.2, 1, (getPlayer()->getId())}} } });

	//Test
	std::unique_ptr<Button> textTest = std::unique_ptr<Button>{ new Button{GraphicRect{120, 50, Color{0, 0, 180, 180}}, "TEST", gameWindow.getRenderer(), Position<>{50, 50}, Font{50} } };
	buttonList.push_back(std::move(textTest));
}

LifeForm* GameLoop::getPlayer() { return lifeFormList.getPlayer(); }

bool GameLoop::update() {
	timeSinceGameStart = SDL_GetTicks();
	//First, see if there is any input from the user
	handleEvent(event);

	refreshEntities();

	gameWindow.getCamera().setPosition(Position<>{static_cast<long>(lifeFormList.getPlayer()->getPosition().x)-SCREEN_WIDTH/2, static_cast<long>(lifeFormList.getPlayer()->getPosition().y)-SCREEH_HEIGHT/2});

	gameWindow.clear();//Then clear the screen
	//Then put everything in the renderer


	map.render(gameWindow.getRenderer(), gameWindow.getCamera());

	renderEntities(gameWindow.getRenderer(), gameWindow.getCamera());

	gameWindow.update();//Then print it
	return keepGoing;
}

void GameLoop::handleEvent(Event& event) {
	while (event.pollEvent()) {
		event.handleEvent(this);
	}
}

void GameLoop::refreshEntities() {
	float deltaTime = static_cast<float>(static_cast<double>(clock.resetTime()) / (1000 * 1000));
	lifeFormList.refreshList(map, deltaTime);
}

void GameLoop::renderEntities(SDL_Renderer* renderer, Camera& camera) {
	lifeFormList.renderList(renderer, camera);
	Position<> relPlayerPosition{ camera.absoluteToRelative(static_cast<int>(getPlayer()->getPosition().x), static_cast<int>(getPlayer()->getPosition().y)) };
	//Render the limited vision
	Position<> line1{ camera.absoluteToRelative(static_cast<long int>(getPlayer()->getPosition().x + getPlayer()->getSightRange() * cos(getPlayer()->getFacingDirection().get()+getPlayer()->getSightArea())),
		static_cast<long int>(getPlayer()->getPosition().y + getPlayer()->getSightRange() * sin(getPlayer()->getFacingDirection().get()+getPlayer()->getSightArea()))) };
	Position<> line2{ camera.absoluteToRelative(static_cast<long int>(getPlayer()->getPosition().x + getPlayer()->getSightRange() * cos(getPlayer()->getFacingDirection().get()-getPlayer()->getSightArea())),
		static_cast<long int>(getPlayer()->getPosition().y + getPlayer()->getSightRange() * sin(getPlayer()->getFacingDirection().get()-getPlayer()->getSightArea()))) };
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, relPlayerPosition.x, relPlayerPosition.y, line1.x, line1.y);
	SDL_RenderDrawLine(renderer, relPlayerPosition.x, relPlayerPosition.y, line2.x, line2.y);
	//player.render(renderer, camera);//Put the player last so he is above everything else

	for (auto it = buttonList.begin(); it != buttonList.end(); it++)
		(**it).render(renderer);
	console.render(renderer);
}

GameLoop::~GameLoop()
{
}
