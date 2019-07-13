#include "../../header/Command/Stop.h"
#include "../../header/GameLoop.h"


Stop::Stop()
	:Command{ "pl_stop" }
{
}

void Stop::execute(GameLoop* gameLoop, const std::vector<float>& args) const {
	gameLoop->getPlayer()->clearAction();
}

Stop::~Stop()
{
}
