#include "CommandList.h"



CommandList::CommandList(std::set<Command> commandList)
	:commandList{ std::move(commandList) }
{
}

bool CommandList::executeCommand(const std::string& commandName, GameLoop* gameLoop, const std::vector<float>& args) const {
	std::set<Command>::iterator search = commandList.find(commandName);
	if (search == commandList.end())
		return false;
	search->execute(gameLoop, args);
	return true;
}

CommandList::~CommandList()
{
}
