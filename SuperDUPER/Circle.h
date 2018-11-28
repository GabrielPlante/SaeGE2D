#pragma once
#include "Renderable.h"
#include "Color.h"
#include <vector>

class Circle : public Renderable
{
public:
	Circle(int x, int y, int radius, Color color);
	void setPosition(int x, int y) override;
	void render(SDL_Renderer* renderer) override;
	~Circle();
protected:
	Color color;
private:
	int radius;
	std::vector<SDL_Point> circlePoints;
};

