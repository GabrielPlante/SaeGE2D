#pragma once
#include "Command.h"
#include "GameLoop.h"
class OpenConsole :
	public Command
{
public:
	OpenConsole();
	virtual void execute(GameLoop* gameLoop, const std::vector<float>& args = std::vector<float>{}) const override {
		gameLoop->getConsole()->open();
	}
	~OpenConsole();
};

