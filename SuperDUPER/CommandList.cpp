#include "CommandList.h"
#include "Quit.h"
#include "Attack.h"
#include "Move.h"
#include "ValueChange.h"
#include "Command.h"



CommandList::CommandList()
{
	commandList.insert(std::move(std::unique_ptr<Command>{new Quit{}}));
	commandList.insert(std::move(std::unique_ptr<Command>{new Attack{}}));
	commandList.insert(std::move(std::unique_ptr<Command>{new Move{}}));
}

bool CommandList::executeCommand(const std::string& commandName, GameLoop* gameLoop, const std::vector<float>& args) const {
	std::unique_ptr<Command> command{ new Command{commandName} };
	auto search = commandList.find(command);
	if (search == commandList.end())
		return false;
	(**search).execute(gameLoop, args);
	return true;
}

CommandList::~CommandList()
{
}
