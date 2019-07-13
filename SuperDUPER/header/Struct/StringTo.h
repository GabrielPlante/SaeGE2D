#pragma once
#include <string>
#include "../Command/CommandError/CommandError.h"

struct StringTo
{
	static float toFloat(const std::string& arg) {
		float value;
		try {
			value = std::stof(arg);
		}
		catch (const std::invalid_argument&) {
			throw CommandError{ "Arguments must be float" };
		}
		catch (const std::out_of_range& ex) {
			throw CommandError{ ex.what() };
		}
		return value;
	}

};