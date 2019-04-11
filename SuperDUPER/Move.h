#pragma once
#include "Command.h"
class Move :
	public Command
{
public:
	Move();
	void execute(GameLoop* gameLoop, const std::vector<float> args) override;
	~Move();
};

