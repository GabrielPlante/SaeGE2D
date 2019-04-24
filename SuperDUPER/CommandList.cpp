#include "CommandList.h"
#include "Quit.h"
#include "Attack.h"
#include "Move.h"
#include "OpenConsole.h"
#include "Stop.h"



CommandList::CommandList()
{
	commandList.insert(std::move(std::unique_ptr<Command>{new Quit{}}));
	commandList.insert(std::move(std::unique_ptr<Command>{new Attack{}}));
	commandList.insert(std::move(std::unique_ptr<Command>{new Move{}}));
	commandList.insert(std::move(std::unique_ptr<Command>{new OpenConsole{}}));
	commandList.insert(std::move(std::unique_ptr<Command>{new Stop{}}));
}

bool CommandList::executeCommand(const std::string& commandName, GameLoop* gameLoop, const std::vector<float>& args) {
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
