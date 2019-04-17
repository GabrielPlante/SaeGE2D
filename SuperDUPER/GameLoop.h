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
	std::list<std::unique_ptr<LifeForm>>* getLifeForms() { return &lifeForms; }
	std::vector<std::unique_ptr<Button>>* getButtonList() { return &buttonList; }
	LifeForm* getPlayer() { return &(**lifeForms.begin()); }
	Camera* getCamera() { return &(gameWindow.getCamera()); }
	Console* getConsole() { return &console; }
	void quit() { keepGoing = false; }
	~GameLoop();
private:
	Window gameWindow;
	Map map;
	Event event;
	std::list<std::unique_ptr<LifeForm>> lifeForms;
	Uint32 timeSinceGameStart;
	Clock clock;
	std::vector<std::unique_ptr<Button>> buttonList;
	bool keepGoing = true;
	Console console;
};

