#pragma once
#include "Command.h"
#include <set>
#include <memory>

class Command;
struct CommandCompare {
	bool operator()(const std::unique_ptr<Command>& c1, const std::unique_ptr<Command>& c2) const {
		return c1->getName() < c2->getName();
	}
};

class GameLoop;
class CommandList
{
public:
	CommandList();
	void addCommand(std::unique_ptr<Command> command) { commandList.insert(std::move(command)); }
	//Return true if the command executed properly
	bool executeCommand(const std::string& commandName, GameLoop* gameLoop, const std::vector<float>& args = std::vector<float>{});
	~CommandList();
private:
	std::set<std::unique_ptr<Command>, CommandCompare> commandList;
	bool isInit = false;
};

