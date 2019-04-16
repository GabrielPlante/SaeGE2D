#pragma once
#include <string>
class Item
{
public:
	Item(const std::string& name, short mass);
	void setMass(short newMass) { mass = newMass; }
	short getMass() const { return mass; }
	~Item();
private:
	std::string name;
	short mass;
};

