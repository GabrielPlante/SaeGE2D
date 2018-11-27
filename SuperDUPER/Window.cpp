#include "Window.h"



Window::Window(const int screenWith, const int screenHeight)
{
	//Initialise SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		throw std::runtime_error("SDL_INIT_VIDEO failed");
	//Create window
	gWindow = SDL_CreateWindow("My super game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWith, screenHeight, SDL_WINDOW_SHOWN);
	if (!gWindow)
		throw std::runtime_error("SDL_CreateWindow failed");
	//Create renderer
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!gRenderer)
		throw std::runtime_error("SDL_CreateRenderer failed");
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
}

void Window::clear() {
	SDL_RenderClear(gRenderer);
}

void Window::update() {
	SDL_RenderPresent(gRenderer);
}

SDL_Renderer* Window::getRenderer() {
	return gRenderer;
}

Window::~Window()
{
	//Destroy
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = nullptr;
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}
