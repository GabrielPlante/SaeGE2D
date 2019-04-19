#include "CommandList.h"
#include "Quit.h"
#include "Attack.h"
#include "Move.h"
#include "ValueChange.h"
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
	if (!isInit) {
		commandList.insert(std::move(std::unique_ptr<Command>{new ValueChange<int>{ "pl_speed", gameLoop->getLifeForms()->begin()->get()->getActualSpeedPtr() }}));
		commandList.insert(std::move(std::unique_ptr<Command>{new ValueChange<float>{ "pl_rotatingspeed", gameLoop->getLifeForms()->begin()->get()->getRotatingSpeedPtr() }}));
		commandList.insert(std::move(std::unique_ptr<Command>{new ValueChange<short>{ "pl_healthpoint", gameLoop->getLifeForms()->begin()->get()->getHealtPointPtr() }}));
		commandList.insert(std::move(std::unique_ptr<Command>{new ValueChange<float>{ "pl_position_x", gameLoop->getLifeForms()->begin()->get()->getPositionXPtr() }}));
		commandList.insert(std::move(std::unique_ptr<Command>{new ValueChange<float>{ "pl_position_y", gameLoop->getLifeForms()->begin()->get()->getPositionYPtr() }}));
		isInit = true;
	}
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
