#pragma once
#include <SDL.h>
#include "Rectangle.h"
#include "Position.h"

class Camera
{
public:
	Camera(int x, int y, int w, int h);
	void move(int deltaX, int deltaY);
	Position<> relativeToAbsolute(int x, int y) const;
	Position<> absoluteToRelative(long int x, long int y) const;
	void resize(double deltaW, double deltaH);
	void resize(int w, int h);
	bool isInCamera(const Rectangle& object) const;
	~Camera();
private:
	Rectangle camera;
};

