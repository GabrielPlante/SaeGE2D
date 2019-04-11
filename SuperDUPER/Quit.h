#pragma once
#include "Command.h"
class Quit :
	public Command
{
public:
	Quit();
	void execute(GameLoop* gameLoop, const std::vector<float> args) override;
	~Quit();
};

