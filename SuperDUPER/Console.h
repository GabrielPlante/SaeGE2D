#pragma once
#include "Rectangle.h"
class Console
{
public:
	Console(Rectangle rectangle);
	~Console();
private:
	Rectangle rectangle;
};

