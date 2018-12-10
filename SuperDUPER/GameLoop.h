#pragma once
#include "Window.h"
#include "Event.h"
#include "Circle.h"
#include "Map.h"
#include "Character.h"
#include <vector>

class GameLoop
{
public:
	GameLoop();
	bool update();
	bool handleEvent(Event& event);
	void refreshEntities();
	void renderEntities(SDL_Renderer* renderer, Camera& camera);
	~GameLoop();
private:
	Window gameWindow;
	Map map;
	Event event;
	std::vector<Entity> entities;
	Character player;
	Uint32 timeSinceGameStart;
};

