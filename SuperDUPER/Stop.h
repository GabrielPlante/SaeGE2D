#pragma once
#include "Command.h"
class Stop :
	public Command
{
public:
	Stop();
	void execute(GameLoop* gameLoop, const std::vector<float>& args = std::vector<float>{}) const override;
	~Stop();
};

