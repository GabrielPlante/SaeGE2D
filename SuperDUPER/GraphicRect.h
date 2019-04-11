#pragma once
#include "Renderable.h"
#include "Color.h"

//The graphic representation of a rectangle
//The position of the rectanle is the position of the left upper corner
class GraphicRect : public Renderable
{
public:
	GraphicRect(short w, short h, Color color);
	void render(SDL_Renderer* renderer, const Camera& camera, const Position<>& position) const override;
	//To render in position relative to the window
	void renderWithoutCamera(SDL_Renderer* renderer, const Position<>& position) const;
	bool pointIsIn(const Position<>& point, const Position<>& position) const override {
		return point.x > position.x && point.x < position.x + w && point.y > position.y && point.y < position.y + h;
	}
	const Color& getColor() const { return color; }
	void changeColor(Color newColor) { color = newColor; }
	short getW() const { return w; }
	short getH() const { return h; }
	~GraphicRect();
protected:
	short w;
	short h;
	Color color;
};

