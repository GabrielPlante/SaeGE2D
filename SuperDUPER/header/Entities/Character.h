#pragma once
#include "LifeForm.h"
#include "../Renderable/Circle.h"
class Character :
	public LifeForm
{
public:
	Character(int x, int y, Color color);
	void render(SDL_Renderer* renderer, const Camera& camera) const override;
	bool refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime, const std::vector<float>& gameValues) override;
	~Character();
private:
};
