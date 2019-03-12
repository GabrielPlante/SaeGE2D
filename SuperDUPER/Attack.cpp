#include "Attack.h"
#include "StringSplit.h"



Attack::Attack()
	:Command("pl")
{
}

void Attack::execute(GameLoop* gameLoop, const std::string& arg) {
	std::vector<std::string> stringPos = StringSplit::split(arg, ' ');
	int x = std::stoi(stringPos[0]) * stringPos[0][0] == '-' ? -1 : 1;
	int y = std::stoi(stringPos[1]) * stringPos[1][0] == '-' ? -1 : 1;
	Position<> attackPos{ gameLoop->getCamera()->relativeToAbsolute(x, y) };
	gameLoop->getPlayer()->attack(attackPos);
}

Attack::~Attack()
{
}
