#include "../../header/Command/Command.h"
#include "../../header/GameLoop.h"


Command::Command(std::string name)
	:name{ std::move(name) }
{
}

Command::~Command()
{
}
