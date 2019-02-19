#include "Camera.h"


///screen + camera = world
Camera::Camera(int x, int y, int w, int h)
	:camera{ x, y, w, h }
{
}

void Camera::move(int deltaX, int deltaY) {
	camera.x += deltaX;
	camera.y += deltaY;
}

//Convert a position relative to the screen to a absolute in-game position
Position<> Camera::relativeToAbsolute(int x, int y) const {
	return Position<>{ x + camera.x, y + camera.y };
}

//Convert a absolute in-game position to a position relative to the screen
Position<> Camera::absoluteToRelative(long int x, long int y) const {
	return Position<>{ x - camera.x, y - camera.y };
}

void Camera::resize(float deltaW, float deltaH) {
	camera.w = static_cast<int>(camera.w*deltaW);
	camera.h = static_cast<int>(camera.h*deltaH);
}

void Camera::resize(int w, int h) {
	camera.w = w;
	camera.h = h;
}

Camera::~Camera()
{
}
