#pragma once
#include "Renderable.h"
#include "Color.h"
#include <vector>

class Circle : public Renderable
{
public:
	Circle(int x, int y, int radius, Color color);
	void render(SDL_Renderer* renderer) override;
	~Circle();
protected:
	Color color;
private:
	std::vector<SDL_Point> circlePoints;
};

