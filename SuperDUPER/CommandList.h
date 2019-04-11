#pragma once
#include "Command.h"
#include <set>
#include "GameLoop.h"
class CommandList
{
public:
	CommandList(std::set<Command> commandList = std::set<Command>{});
	//Return true if the command executed properly
	void addCommand(Command command) { commandList.insert(command); }
	bool executeCommand(const std::string& commandName, GameLoop* gameLoop, const std::vector<float>& args) const;
	~CommandList();
private:
	std::set<Command> commandList;
};

