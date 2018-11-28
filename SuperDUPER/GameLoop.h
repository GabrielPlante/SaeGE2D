#pragma once
#include "Window.h"
#include "Event.h"
#include "Circle.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <memory>

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
	std::vector<std::unique_ptr<Entity>> entities;
	Uint32 timeSinceGameStart;
};

