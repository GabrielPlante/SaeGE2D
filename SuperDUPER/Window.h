#pragma once
#include <SDL.h>
#include "Viewport.h"
#include <stdexcept>

class Window
{
public:
	Window(const int screenWith, const int screenHeight);
	void clear();
	void update();
	SDL_Renderer* getRenderer();
	Viewport& getViewport();
	~Window();
private:
	SDL_Window* gWindow{ nullptr };
	Viewport viewport;
	SDL_Renderer* gRenderer{ nullptr };
};
