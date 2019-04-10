#include <iostream>
#include <chrono>
#include <thread>
#include "GameLoop.h"

int main(int argc, char* args[]) {
	constexpr double maxFps = 60;
	constexpr long int timeBetweenFrame{ static_cast<long int>(1000*1000 / maxFps) };
	
	GameLoop gameLoop;

	auto timeAtLastFrame = std::chrono::high_resolution_clock::now();

	//What happen in the game each frame is in update(), what's inside the loop is only the frame capper
	while (gameLoop.update()) {
		auto timeSinceLastFrame{ std::chrono::high_resolution_clock::now() - timeAtLastFrame };
		//Cast timeSinceLastFrame to something simpler
		const long long elapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeSinceLastFrame).count();
		//Check if the program render the frame in less time than the user want
		if (elapsed < timeBetweenFrame)//To cap fps
			std::this_thread::sleep_for(std::chrono::microseconds(timeBetweenFrame - elapsed));
		timeAtLastFrame = std::chrono::high_resolution_clock::now();
	}
	return 0;
}