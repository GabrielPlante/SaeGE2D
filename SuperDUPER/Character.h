#pragma once
#include "LifeForm.h"
#include "Circle.h"
class Character :
	public LifeForm
{
public:
	Character(int x, int y, Color color);
	bool refresh() override;
	~Character();
};

