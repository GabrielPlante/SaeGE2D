#include "Quit.h"



Quit::Quit()
{
}

void Quit::execute(GameLoop* gameLoop, const std::string& arg) {
	gameLoop->quit();
}

Quit::~Quit()
{
}
