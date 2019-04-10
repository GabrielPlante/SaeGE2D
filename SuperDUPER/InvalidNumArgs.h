#pragma once
#include "CommandError.h"
class InvalidNumArgs :
	public CommandError
{
public:
	InvalidNumArgs(short wanted, short got);
	~InvalidNumArgs();
};

