#pragma once
#include <string>
#include <vector>


//enum class Prefix {None, Player };

class GameLoop;
class Command
{
public:
	Command(std::string name);
	//The string given must be the arguments only, without the command name
	virtual void execute(GameLoop* gameLoop, const std::vector<float>& args = std::vector<float>{}) const {}
	const std::string& getName() const { return name; }
	bool operator<(const Command& other) const { return name < other.getName(); }
	bool operator<(const std::string& other) const { return name < other; }
	~Command();
private:
	std::string name;
};

