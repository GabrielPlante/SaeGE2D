#include "Move.h"
#include "StringSplit.h"
#include "CommandError.h"


Move::Move()
	:Command{"pl_move"}
{
}

void Move::execute(GameLoop* gameLoop, const std::string& arg) {
	std::vector<std::string> stringPos;
	try {
	stringPos = StringSplit::split(arg, ' ');
	}
	catch (...) {
		throw CommandError("Split error");
	}
	if (stringPos.size() != 2) {
		throw CommandError("Invalid number of argument. Wanted: 2, got: " + stringPos.size());
	}
	int x, y;
	try {
		x = std::stoi(stringPos[0]) * stringPos[0][0] == '-' ? -1 : 1;
		y = std::stoi(stringPos[1]) * stringPos[1][0] == '-' ? -1 : 1;
	}
	catch (const std::invalid_argument&) {
		throw CommandError{ "Invalid argument" };
	}
	catch (const std::out_of_range&) {
		throw CommandError{ "Out of range" };
	}
	gameLoop->getPlayer()->setDestination(gameLoop->getCamera()->relativeToAbsolute(x, y));
}

Move::~Move()
{
}
