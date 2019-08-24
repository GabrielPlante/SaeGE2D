#include "Move.h"
#include "StringSplit.h"
#include "CommandError.h"
#include "InvalidNumArgs.h"
#include "GameLoop.h"


Move::Move()
	:Command{"pl_move"}
{
}

void Move::execute(GameLoop* gameLoop, const std::vector<float>& args) const {
	/*if (args.size() != 2 && args.size() != 0)
		throw InvalidNumArgs{ 2, static_cast<int>(args.size()) };
	if (args.size() == 0)
		gameLoop->getConsole()->addText(std::to_string(gameLoop->getPlayer()->getPosition().x) + " " + std::to_string(gameLoop->getPlayer()->getPosition().y));
	else
		gameLoop->getPlayer()->setDestination(Position<>{static_cast<int>(args[0]), static_cast<int>(args[1])});*/
}

Move::~Move()
{
}
