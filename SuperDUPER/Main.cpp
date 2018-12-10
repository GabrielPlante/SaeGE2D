#include <iostream>
#include "GameLoop.h"

int main(int argc, char* args[]) {
	constexpr int maxFps = 60;
	const int timeBetweenFrame{ 1000 / maxFps };

	GameLoop gameLoop;

	Uint32 timeAtLastFrame = SDL_GetTicks();

	while (gameLoop.update()) {
		int timeSinceLastFrame{ static_cast<int>(SDL_GetTicks() - timeAtLastFrame) };
		if (timeSinceLastFrame < timeBetweenFrame)//To cap fps
			SDL_Delay(timeBetweenFrame - timeSinceLastFrame);
		//std::cout << SDL_GetTicks() - timeAtLastFrame << std::endl;//Print the real time between two frames
		timeAtLastFrame = SDL_GetTicks();
	}
	return 0;
}