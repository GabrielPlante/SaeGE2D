#pragma once
#include "Window.h"
#include "Event.h"
#include "Circle.h"
#include "Map.h"
#include "Entity.h"
#include <vector>

class GameLoop
{
public:
	GameLoop();
	bool update();
	~GameLoop();
private:
	Window gameWindow{ 1200, 600 };
	Map map;
	Event event;
	std::vector<Entity> entities;
	Uint32 timeSinceGameStart;
};

