#pragma once
#include "GameLoop.h"
#include <string>

//enum class Prefix {None, Player };

class Command
{
public:
	Command(std::string name);
	//The string given must be the arguments only, without the command name
	virtual void execute(GameLoop* gameLoop, const std::string& = "") = 0;
	const std::string& getName() const { return name; }
	~Command();
private:
	std::string name;
};

