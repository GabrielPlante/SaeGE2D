#pragma once
#include <SDL.h>
#include "Camera.h"
#include <stdexcept>

class Window
{
private:
	SDL_Window* gWindow{ nullptr };
	Camera camera;
	SDL_Renderer* gRenderer{ nullptr };

public:
	//Constructor
	Window(const int screenWith, const int screenHeight);

	//Clear the window (call before drawing anything)
	void clear() {
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);
	}

	//Render the window (call after drawing everything)
	void update() { SDL_RenderPresent(gRenderer); }

	//Get the renderer, required to draw anything
	SDL_Renderer* getRenderer() { return gRenderer; }

	//Get the camera, need to be moved out of the game engine
	Camera& getCamera() { return camera; }

	//Destructor
	~Window();
};
