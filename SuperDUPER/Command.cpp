#include "Command.h"



Command::Command(std::string name)
	:name{ std::move(name) }
{
}

Command::~Command()
{
}
