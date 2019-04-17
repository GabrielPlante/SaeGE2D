#include <iostream>
#include "Clock.h"
#include <thread>
#include "GameLoop.h"
#include "ValueChange.h"

int main(int argc, char* args[]) {
	constexpr double maxFps = 60;
	constexpr long int timeBetweenFrame{ static_cast<long int>(1000*1000 / maxFps) };

	GameLoop gameLoop;

	Clock clock;

	//What happen in the game each frame is in update(), what's inside the loop is only the frame capper
	while (gameLoop.update()) {
		auto elapsed = clock.resetTime();
		//Check if the program render the frame in less time than the user want
		if (elapsed < timeBetweenFrame)//To cap fps
			std::this_thread::sleep_for(std::chrono::microseconds(timeBetweenFrame - elapsed));
	}
	return 0;
}