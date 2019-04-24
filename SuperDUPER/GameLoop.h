#pragma once
#include "Window.h"
#include "Event.h"
#include "Circle.h"
#include "Map.h"
#include "Character.h"
#include <list>
#include "Button.h"
#include "Clock.h"
#include "Console.h"
#include "LifeFormList.h"

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

