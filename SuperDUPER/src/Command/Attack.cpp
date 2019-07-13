#include "../../header/Command/Attack.h"
#include "../../header/Struct/StringSplit.h"
#include "../../header/Command/CommandError/InvalidNumArgs.h"
#include "../../header/GameLoop.h"


Attack::Attack()
	:Command("pl_attack")
{
}

void Attack::execute(GameLoop* gameLoop, const std::vector<float>& args) const {
	if (args.size() != 2)
		throw InvalidNumArgs{ 2, static_cast<int>(args.size()) };
	gameLoop->getPlayer()->attack(Position<>{static_cast<int>(args[0]), static_cast<int>(args[1])});
}

Attack::~Attack()
{
}
