#pragma once
#include <SDL.h>
#include "Struct/Rectangle.h"
#include "Struct/Position.h"

class Camera
{
public:
	Camera(int x, int y, int w, int h);
	void move(int deltaX, int deltaY);
	void setPosition(Position<> newPos);
	//Convert a position relative to the screen to a absolute in-game position
	Position<> relativeToAbsolute(int x, int y) const { return Position<>{ x + camera.x, y + camera.y }; }
	//Convert a absolute in-game position to a position relative to the screen
	Position<> absoluteToRelative(long int x, long int y) const { return Position<>{ x - camera.x, y - camera.y }; }
	void zoom(float deltaW, float deltaH);
	void resize(int w, int h);
	//Take absolute coordinate
	bool isInCamera(const Rectangle& object) const { return camera.overlap(object); };
	~Camera();
private:
	Rectangle camera;
};

