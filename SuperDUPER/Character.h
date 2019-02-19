#pragma once
#include "LifeForm.h"
#include "Circle.h"
class Character :
	public LifeForm
{
public:
	Character(int x, int y, Color color);
	void render(SDL_Renderer* renderer, const Camera& camera) const;
	bool refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms) override;
	~Character();
private:
};

