#include "InvalidNumArgs.h"



InvalidNumArgs::InvalidNumArgs(short wanted, short got)
	: CommandError{ "Invalid number of arguments. Wanted: " + std::to_string(wanted) + ", got: " + std::to_string(got) }
{
}


InvalidNumArgs::~InvalidNumArgs()
{
}
