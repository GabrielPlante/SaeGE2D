#pragma once
#include "Position.h"
#include <chrono>
struct Movement
{
public:
	Movement(Position<float> initialPosition, Angle initialFacingDirection)
		: position{ initialPosition }, facingDirection{ initialFacingDirection }
	{}
	//deltaTime is now - time at last frame / 1000 * 1000
	Position<float> movementCalculator(int speed, float deltaTime) const {
		const float multiplyingFactor = speed * deltaTime;
		return Position<float>{cos(facingDirection.get())*multiplyingFactor, sin(facingDirection.get())*multiplyingFactor};
	}
	void move(int speed, float deltaTime) {
		Position<float> posOffset = movementCalculator(speed, deltaTime);
		move(posOffset);
	}
	void move(Position<float> posOffset) {
		position.x += posOffset.x;
		position.y += posOffset.y;
	}
	Position<float> getPosition() const { return position; }
	Angle getFacingDirection() const { return facingDirection; }
private:
	Position<float> position;
	Angle facingDirection;
};

