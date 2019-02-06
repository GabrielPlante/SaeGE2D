#pragma once
#include "Entity.h"
#include <math.h>
#include "Destination.h"
#include <chrono>

enum class Friendliness {Neutral, Friend, Enemy};

enum class ActionState { AtRest, Moving, Attacking };

class LifeForm :
	public Entity
{
public:
	LifeForm(double x, double y, int speed, int healthPoint, Friendliness friendliness = Friendliness::Neutral,
		double facingDirection = 0, double rotatingSpeed = .1, int sightRange = 1000, float sightArea = 1);//The default constructor
	bool refresh() override;//Method to call each frame
	bool move(const Destination& destination, const int speed);//Move toward a direction at a certain speed, instantaneous, call setDestination to have a repercution
	void rotate(double directionAngle, double rotatingSpeed);//Same as move but for the rotation
	void setDestination(const Destination& destination);
	void setRotatingDestination(const Destination& destination);
	void attack(const Destination& destination);
	bool isInSight(const Position<double>& position) const;//return true if a position is in sight
	int getSightRange() const { return sightRange; }
	float getSightArea() const { return sightArea; }
	double getFacingDirection() const { return facingDirection; }
	Friendliness getFriendliness() const { return friendliness; }
	~LifeForm();
private:
	const int id;
	static int idCount;//Each lifeForm has a unique ID
	int actualSpeed;
	int sightRange;
	float sightArea;
	int baseSpeed;//Speed unit is : pixel/sec
	double rotatingSpeed;
	int healthPoint;
	//All angle are in radian, in [0-2PI]
	double directionAngle;//The direction the lifeform want to turn to
	double facingDirection;//The direction the lifeform currently face
	Destination destination;
	ActionState actionState = ActionState::AtRest;
	bool isTurning = false;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastMovement;
	std::chrono::time_point<std::chrono::high_resolution_clock> timeAtLastRotation;
	Friendliness friendliness;
};

