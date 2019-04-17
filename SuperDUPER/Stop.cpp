#include "Stop.h"
#include "GameLoop.h"


Stop::Stop()
	:Command{ "pl_stop" }
{
}

void Stop::execute(GameLoop* gameLoop, const std::vector<float>& args) const {
	gameLoop->getLifeForms()->begin()->get()->clearAction();
}

Stop::~Stop()
{
}
