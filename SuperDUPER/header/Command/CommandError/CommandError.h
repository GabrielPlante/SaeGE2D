#pragma once
#include <exception>
#include <string>
class CommandError
	:public std::runtime_error
{
public:
	CommandError(const std::string& error);
	~CommandError();
private:
	std::string message;
};

