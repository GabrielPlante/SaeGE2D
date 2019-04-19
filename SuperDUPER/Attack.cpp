#include "Attack.h"
#include "StringSplit.h"
#include "InvalidNumArgs.h"
#include "GameLoop.h"


Attack::Attack()
	:Command("pl_attack")
{
}

void Attack::execute(GameLoop* gameLoop, const std::vector<float>& args) const {
	if (args.size() != 2)
		throw InvalidNumArgs{ 2, static_cast<short>(args.size()) };
	gameLoop->getPlayer()->attack(Position<>{static_cast<int>(args[0]), static_cast<int>(args[1])});
}

Attack::~Attack()
{
}
