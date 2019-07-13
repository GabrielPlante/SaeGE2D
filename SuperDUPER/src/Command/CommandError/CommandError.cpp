#include "../../../header/Command/CommandError/CommandError.h"



CommandError::CommandError(const std::string& error)
	:runtime_error(error)
{
}


CommandError::~CommandError()
{
}
