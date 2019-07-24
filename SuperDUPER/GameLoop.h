//TODO move out of the game engine what need to be moved
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
private:
	//This contain all the gameValues, given to each entity each frame
	std::vector<float> gameValues;
	//Window that contain the game
	Window gameWindow;
	//The map of the game
	Map map;
	//The event, treat input event, may be moved out
	Event event;
	Uint32 timeSinceGameStart;
	//The official clock of the game
	Clock clock;
	//Maybe need to be a list to make the access faster
	std::vector<std::unique_ptr<Button>> buttonList;
	bool keepGoing = true;
	Console console;
	//The lifeform list need to be an entitie list
	LifeFormList lifeFormList;

public:
	//Default constructor
	GameLoop();

	//The method to call each frame, all of what happen in the game each frame happen here. It return true if the game is still going
	bool update();

	//Handle event of the system, maybe need to be moved to the game itself not the engine
	void handleEvent(Event& event);

	//Refresh all the entities
	void refreshEntities();

	//Render all the entities
	void renderEntities(SDL_Renderer* renderer, Camera& camera);

	//Add an entity to the entity list
	size_t addEntity(std::unique_ptr<LifeForm> lifeForm) { return lifeFormList.addLifeForm(std::move(lifeForm)); }

	//Return the window that contain the game (need to be moved out of the game engine)
	Window* getGameWindow() { return &gameWindow; }

	//Get the map
	Map* getMap() { return &map; }

	//Get the button list
	std::vector<std::unique_ptr<Button>>* getButtonList() { return &buttonList; }

	//Get the player, need to be moved out of the game engine
	LifeForm* getPlayer();

	//Get the camera, need to be moved out of the game engine
	Camera* getCamera() { return &(gameWindow.getCamera()); }

	//Get the console
	Console* getConsole() { return &console; }

	//Quit the game
	void quit() { keepGoing = false; }
};

