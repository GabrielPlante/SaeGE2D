#pragma once
#include "Window.h"
#include "Event.h"
#include "Renderable/Circle.h"
#include "Map/Map.h"
#include "Entities/Character.h"
#include <list>
#include "Renderable/UI/Button.h"
#include "Struct/Clock.h"
#include "Renderable/UI/Console.h"
#include "Entities/LifeFormList.h"

class GameLoop
{
public:
	GameLoop();
	bool update();
	void handleEvent(Event& event);
	void refreshEntities();
	void renderEntities(SDL_Renderer* renderer, Camera& camera);
	Window* getGameWindow() { return &gameWindow; }
	Map* getMap() { return &map; }
	std::vector<std::unique_ptr<Button>>* getButtonList() { return &buttonList; }
	LifeForm* getPlayer();
	LifeFormList* getLifeFormList() { return &lifeFormList; }
	Camera* getCamera() { return &(gameWindow.getCamera()); }
	Console* getConsole() { return &console; }
	void quit() { keepGoing = false; }
	~GameLoop();
private:
	std::vector<float> gameValues;
	Window gameWindow;
	Map map;
	Event event;
	Uint32 timeSinceGameStart;
	Clock clock;
	std::vector<std::unique_ptr<Button>> buttonList;
	bool keepGoing = true;
	Console console;
	LifeFormList lifeFormList;
};

