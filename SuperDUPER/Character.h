#pragma once
#include "LifeForm.h"
#include "Circle.h"
class Character :
	public LifeForm
{
public:
	Character(int x, int y, Color color);
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	bool refresh() override;
	~Character();
private:
};

