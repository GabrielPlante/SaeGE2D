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
IntPosition Camera::relativeToAbsolute(int x, int y) const {
	return IntPosition{ x + camera.x, y + camera.y };
}

//Convert a absolute in-game position to a position relative to the screen
IntPosition Camera::absoluteToRelative(long int x, long int y) const {
	return IntPosition{ x - camera.x, y - camera.y };
}

void Camera::resize(double deltaW, double deltaH) {
	camera.w = static_cast<int>(camera.w*deltaW);
	camera.h = static_cast<int>(camera.h*deltaH);
}

void Camera::resize(int w, int h) {
	camera.w = w;
	camera.h = h;
}

bool Camera::isInCamera(const Rectangle& object) const {
	return camera.overlap(object);
}

Camera::~Camera()
{
}
