#pragma once
#include <SDL.h>
#include "Camera.h"
#include <stdexcept>

class Window
{
public:
	Window(const int screenWith, const int screenHeight);
	void clear() {
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);
	}
	void update() { SDL_RenderPresent(gRenderer); }
	SDL_Renderer* getRenderer() { return gRenderer; }
	Camera& getCamera() { return camera; }
	~Window();
private:
	SDL_Window* gWindow{ nullptr };
	Camera camera;
	SDL_Renderer* gRenderer{ nullptr };
};
