#pragma once
#include <SDL.h>
#include "Rectangle.h"
#include "Position.h"

class Camera
{
public:
	Camera(int x, int y, int w, int h);
	void move(int deltaX, int deltaY);
	//Convert a position relative to the screen to a absolute in-game position
	Position<> relativeToAbsolute(int x, int y) const;
	//Convert a absolute in-game position to a position relative to the screen
	Position<> absoluteToRelative(long int x, long int y) const;
	void resize(float deltaW, float deltaH);
	void resize(int w, int h);
	//Take absolute coordinate
	bool isInCamera(const Rectangle& object) const { return camera.overlap(object); };
	~Camera();
private:
	Rectangle camera;
};

