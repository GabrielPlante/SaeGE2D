#include "Quit.h"



Quit::Quit()
	:Command("quit")
{
}

void Quit::execute(GameLoop* gameLoop, const std::vector<float> args) {
	gameLoop->quit();
}

Quit::~Quit()
{
}
