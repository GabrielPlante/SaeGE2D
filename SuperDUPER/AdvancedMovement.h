#pragma once
#include "Position.h"
#include "Destination.h"

//Movement with a destination
struct AdvancedMovement {
	AdvancedMovement() {}
	AdvancedMovement(Destination destination) : destination{ destination } {}
	//Change the position passed by the pointer
	bool move(Position<float>* position, const int speed, float deltaTime) {
		/*previousPosition.x = position->x;
		previousPosition.y = position->y;*/
		//The division of the operation to get the movement according to x and y
		const float dividingMovementFactor = sqrt(pow(destination.getCoordinate().x - position->x, 2) + pow(destination.getCoordinate().y - position->y, 2));
		//We fist calculate the x movement so we can check if the destination.getCoordinate() is reached
		const float movementX = (destination.getCoordinate().x - position->x) * deltaTime * speed / dividingMovementFactor;
		const float movementY = (destination.getCoordinate().y - position->y) * deltaTime * speed / dividingMovementFactor;
		if (movementX > abs(destination.getCoordinate().x - position->x) || movementY > abs(destination.getCoordinate().y - position->y)) {//If the destination.getCoordinate() is reached
			position->x = destination.getCoordinate().x;
			position->y = destination.getCoordinate().y;
			return true;
		}
		else {
			position->x += movementX;
			position->y += movementY;
			return false;
		}
	}
	const Destination& getDestination() const { return destination; }
	void setDestination(Destination newDestination) { destination = newDestination; }
private:
	Destination destination;
};
