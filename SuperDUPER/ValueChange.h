#pragma once
#include "Command.h"
#include "StringTo.h"
#include "InvalidNumArgs.h"
template <typename T>
class ValueChange :
	public Command
{
public:
	ValueChange(std::string name, T * valuePointed) : Command{ name }, valuePointed{ valuePointed }{}
	void execute(GameLoop* gameLoop, const std::vector<float>& args) const override {//gameLoop can be null
		if (args.size() != 1)
			throw InvalidNumArgs(1, static_cast<short>(args.size()));
		*valuePointed = static_cast<T>(args[0]);
	}
private:
	T * valuePointed;
};
