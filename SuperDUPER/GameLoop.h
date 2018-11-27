#pragma once
#include "Window.h"
#include "Event.h"

class GameLoop
{
public:
	GameLoop();
	bool update();
	~GameLoop();
private:
	Window gameWindow{ 1200, 600 };
	Event event;
	Uint32 timeSinceGameStart;
};

