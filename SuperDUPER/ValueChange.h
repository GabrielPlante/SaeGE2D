#pragma once
#include "Command.h"
#include "StringTo.h"
template <typename T>
class ValueChange :
	public Command
{
public:
	ValueChange(std::string name, T * valuePointed) : Command{ name }, valuePointed{ valuePointed }{}
	void execute(GameLoop* gameLoop, const std::string& arg) override {//gameLoop can be null
		*valuePointed = static_cast<T>(StringTo::toFloat(arg));
	}
private:
	T * valuePointed;
};
