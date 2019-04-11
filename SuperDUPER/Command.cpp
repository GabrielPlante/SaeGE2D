#include "Command.h"
#include "GameLoop.h"


Command::Command(std::string name)
	:name{ std::move(name) }
{
}

Command::~Command()
{
}
