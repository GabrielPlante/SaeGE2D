#pragma once
#include "Command.h"
class Attack :
	public Command
{
public:
	Attack();
	void execute(GameLoop* gameLoop, const std::string& arg) override;
	static void execute(GameLoop* gameLoop, int x, int y) { gameLoop->getPlayer()->attack(gameLoop->getCamera()->relativeToAbsolute(x, y)); }
	~Attack();
};

