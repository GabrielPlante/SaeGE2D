#pragma once
#include "GameLoop.h"
#include <string>

//enum class Prefix {None, Player };

class Command
{
public:
	Command(std::string prefix = "");
	virtual void execute(GameLoop* gameLoop, const std::string& = "") = 0;
	//virtual std::string& 
	~Command();
private:
	std::string prefix;
};

