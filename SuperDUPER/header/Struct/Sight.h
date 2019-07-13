#pragma once
#include "Position.h"
#include "Angle.h"
struct Sight
{
	Sight(int sightRange, float sightArea) :sightRange{ sightRange }, sightArea{ sightArea } {}
	//return true if the other pos is in sight of the position given his facing direction
	bool isInSight(const Position<float>& position, const Position<float>& otherPos, const Angle& facingDirection) const {
		if (position.distanceSquared(otherPos) > sightRange*sightRange)
			return false;
		constexpr float PI = 3.14159265f;
		Angle angleEntityPlayer = facingDirection.difference(position.angle(otherPos));
		return (angleEntityPlayer.get() <= sightArea || angleEntityPlayer.get() >= 2 * PI - sightArea);
	}
	float getSightArea() const { return sightArea; }
	int getSightRange() const { return sightRange; }
private:
	float sightArea;//Between 0 (don't see anything) and PI (see everything)
	int sightRange;
};

