#include "Quit.h"



Quit::Quit()
	:Command("quit")
{
}

void Quit::execute(GameLoop* gameLoop, const std::string& arg) {
	gameLoop->quit();
}

Quit::~Quit()
{
}
