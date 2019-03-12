#pragma once
#include "Command.h"
class Move :
	public Command
{
public:
	Move();
	void execute(GameLoop* gameLoop, const std::string& arg) override;
	static void execute(GameLoop* gameLoop, int x, int y) { gameLoop->getPlayer()->setDestination(gameLoop->getCamera()->relativeToAbsolute(x, y)); }
	~Move();
};

