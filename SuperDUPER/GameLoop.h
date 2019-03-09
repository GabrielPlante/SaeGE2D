#pragma once
#include "Window.h"
#include "Event.h"
#include "Circle.h"
#include "Map.h"
#include "Character.h"
#include <list>
#include "TextOnRect.h"

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
	std::list<std::unique_ptr<LifeForm>> lifeForms;
	Uint32 timeSinceGameStart;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastFrame;
	std::unique_ptr<TextOnRect> textTest;
};

