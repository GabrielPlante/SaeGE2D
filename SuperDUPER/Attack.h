#pragma once
#include "Command.h"
class Attack :
	public Command
{
public:
	Attack();
	void execute(GameLoop* gameLoop, const std::vector<float>& args) const override;
	~Attack();
};

