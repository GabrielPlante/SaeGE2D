#include "../../../header/Command/CommandError/InvalidNumArgs.h"



InvalidNumArgs::InvalidNumArgs(int wanted, int got)
	: CommandError{ "Invalid number of arguments. Wanted: " + std::to_string(wanted) + ", got: " + std::to_string(got) }
{
}


InvalidNumArgs::~InvalidNumArgs()
{
}
