#pragma once
#include "Renderable.h"
#include "Color.h"
#include <vector>

class Circle : public Renderable
{
public:
	Circle(int x, int y, int radius, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport) override;
	bool pointIsIn(Position<> point) const override;
	~Circle();
protected:
	Color color;
private:
	int radius;
};

