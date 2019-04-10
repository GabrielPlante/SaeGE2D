#include "Attack.h"
#include "StringSplit.h"
#include "CommandError.h"
#include "InvalidNumArgs.h"


Attack::Attack()
	:Command("pl_attack")
{
}

void Attack::execute(GameLoop* gameLoop, const std::string& arg) {
	std::vector<std::string> stringPos;
	try {
	stringPos = StringSplit::split(arg, ' ');
	}
	catch (...) {
		throw CommandError("Split error");
	}
	if (stringPos.size() != 2) {
		throw InvalidNumArgs{ 2, static_cast<short>(stringPos.size()) };
	}
	int x, y;
	try{
		x = std::stoi(stringPos[0]) * stringPos[0][0] == '-' ? -1 : 1;
		y = std::stoi(stringPos[1]) * stringPos[1][0] == '-' ? -1 : 1;
	}
	catch (const std::invalid_argument& ex) {
		throw CommandError{ ex.what() };
	}
	catch (const std::out_of_range& ex) {
		throw CommandError{ ex.what() };
	}
	gameLoop->getPlayer()->attack(gameLoop->getCamera()->relativeToAbsolute(x, y));
}

Attack::~Attack()
{
}
