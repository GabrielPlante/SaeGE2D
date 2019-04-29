#pragma once
#include <string>
class Item
{
public:
	Item(const std::string& name, int mass);
	void setMass(int newMass) { mass = newMass; }
	int getMass() const { return mass; }
	~Item();
private:
	std::string name;
	int mass;
};

