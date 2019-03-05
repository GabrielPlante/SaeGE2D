#pragma once
#include "Renderable.h"
#include "Color.h"
#include <vector>

class Circle : public Renderable
{
public:
	Circle(short radius, Color color);
	void render(SDL_Renderer* renderer, const Camera& viewport, const Position<>& position) const override;
	bool pointIsIn(const Position<>& point, const Position<>& position) const override;
	~Circle();
protected:
	Color color;
private:
	short radius;
};

