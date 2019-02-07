#pragma once
#include <string>
class Item
{
public:
	Item(const std::string& name, int encumbrance);
	~Item();
private:
	int encumbrance;
	std::string name;
};

