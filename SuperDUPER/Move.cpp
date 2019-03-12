#include "Move.h"
#include "StringSplit.h"


Move::Move()
	:Command{"pl_move"}
{
}

void Move::execute(GameLoop* gameLoop, const std::string& arg) {
	std::vector<std::string> stringPos = StringSplit::split(arg, ' ');
	int x = std::stoi(stringPos[0]) * stringPos[0][0] == '-' ? -1 : 1;
	int y = std::stoi(stringPos[1]) * stringPos[1][0] == '-' ? -1 : 1;
	gameLoop->getPlayer()->setDestination(gameLoop->getCamera()->relativeToAbsolute(x, y));
}

Move::~Move()
{
}
