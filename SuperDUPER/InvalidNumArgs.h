#pragma once
#include "CommandError.h"
class InvalidNumArgs :
	public CommandError
{
public:
	InvalidNumArgs(int wanted, int got);
	~InvalidNumArgs();
};

