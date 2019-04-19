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
	if (args.size() != 2)
		throw InvalidNumArgs{ 2, static_cast<short>(args.size()) };
	gameLoop->getPlayer()->setDestination(Position<>{static_cast<int>(args[0]), static_cast<int>(args[1])});
}

Move::~Move()
{
}
