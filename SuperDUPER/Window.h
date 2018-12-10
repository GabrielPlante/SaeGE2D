#pragma once
#include <SDL.h>
#include "Camera.h"
#include <stdexcept>

class Window
{
public:
	Window(const int screenWith, const int screenHeight);
	void clear();
	void update();
	SDL_Renderer* getRenderer();
	Camera& getCamera();
	~Window();
private:
	SDL_Window* gWindow{ nullptr };
	Camera camera;
	SDL_Renderer* gRenderer{ nullptr };
};
