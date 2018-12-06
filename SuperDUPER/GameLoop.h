#pragma once
#include "Window.h"
#include "Event.h"
#include "Circle.h"
#include "Map.h"
#include "Character.h"
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
	std::unique_ptr<Map> map;
	Event event;
	std::vector<Entity> entities;
	std::shared_ptr<Character> player;
	Uint32 timeSinceGameStart;
};

