#pragma once
#include "StringSplit.h"
#include "StringTo.h"

struct TextToCommand {
	TextToCommand(const std::string& string) {
		if (string != "") {
			std::vector<std::string> splited = StringSplit::split(string, ' ');
			commandName = splited[0];
			for (int i = 1; i != splited.size(); i++)
				args.push_back(StringTo::toFloat(splited[i]));
		}
		else
			commandName = "";
	}
	const std::string& getCommandName() const { return commandName; }
	const std::vector<float>& getArgs() const { return args; }
private:
	std::string commandName;
	std::vector<float> args;
};