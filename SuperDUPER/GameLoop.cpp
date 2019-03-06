#include "GameLoop.h"
#include "RangeWeapon.h"
#include "BasicArrow.h"
constexpr int SCREEN_WIDTH{ 1200 };
constexpr int SCREEH_HEIGHT{ 600 };

GameLoop::GameLoop()
	:map{}, player{ 100, 0, Color(0, 0, 255) }, gameWindow{ SCREEN_WIDTH, SCREEH_HEIGHT }
{
	timeAtLastFrame = std::chrono::high_resolution_clock::now();
	//test
	lifeForms.emplace_back(std::unique_ptr<LifeForm>{new Character(400, 400, Color(128, 128, 128))});
	//lifeForms.emplace_back(std::unique_ptr<LifeForm>{new Character(600, 400, Color(128, 128, 128))});

	player.takeWeaponInHand(std::unique_ptr<Weapon> {new RangeWeapon{ "Basic Bow", 100, 100, 1000, 0.5, std::unique_ptr<Projectile>{new BasicArrow{0, Position<float>{0, 0}, 300, 1000, 100}} } } );
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
			event.mouseEvent(&player, gameWindow.getCamera(), lifeForms);
		}
	}
	return true;
}

void GameLoop::refreshEntities() {
	float deltaTime = static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - timeAtLastFrame).count())
		/ (1000 * 1000);
	timeAtLastFrame = std::chrono::high_resolution_clock::now();
	auto it = lifeForms.begin();
	while (it != lifeForms.end()) {
		if ((**it).refresh(map, lifeForms, deltaTime))
			it = lifeForms.erase(it);
		else
			it++;
	}
	player.refresh(map, lifeForms, deltaTime);
}

void GameLoop::renderEntities(SDL_Renderer* renderer, Camera& camera) {
	for (auto it = lifeForms.begin(); it != lifeForms.end(); it++)
		//Render only if the player can see it
		if (player.isInSight((**it).getPosition()))
			(**it).render(renderer, camera);//Put all the lifeForms
	Position<> relPlayerPosition{ camera.absoluteToRelative(static_cast<int>(player.getPosition().x), static_cast<int>(player.getPosition().y)) };
	//Render the limited vision
	Position<> line1{ camera.absoluteToRelative(static_cast<long int>(player.getPosition().x + player.getSightRange() * cos(player.getFacingDirection().get()+player.getSightArea())),
		static_cast<long int>(player.getPosition().y + player.getSightRange() * sin(player.getFacingDirection().get()+player.getSightArea()))) };
	Position<> line2{ camera.absoluteToRelative(static_cast<long int>(player.getPosition().x + player.getSightRange() * cos(player.getFacingDirection().get()-player.getSightArea())),
		static_cast<long int>(player.getPosition().y + player.getSightRange() * sin(player.getFacingDirection().get()-player.getSightArea()))) };
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawLine(renderer, relPlayerPosition.x, relPlayerPosition.y, line1.x, line1.y);
	SDL_RenderDrawLine(renderer, relPlayerPosition.x, relPlayerPosition.y, line2.x, line2.y);
	player.render(renderer, camera);//Put the player last so he is above everything else
}

GameLoop::~GameLoop()
{
}
