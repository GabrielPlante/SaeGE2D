#pragma once
#include <cmath>
constexpr float PI = 3.14159265f;
struct Angle
{
	Angle(float angle = 0) : angle{ angle } {
		if (angle < 0 || angle > 2 * PI)
			add(0);
	}
	void add(Angle delta) {
		angle += delta.get();
		while (angle < 0)
			angle += 2 * PI;
		while (angle > 2 * PI)
			angle -= 2 * PI;
	}
	float get() const { return angle; }
	float toDegree() const { return 180 * angle / PI; }
	void set(Angle angle) {
		this->angle = angle.get();
		if (angle.get() < 0 || angle.get() > 2 * PI)
			add(0);
	}
	float difference(const Angle other) const {//Result in [-PI;PI]
		float angleDifference = other.get() - angle;
		if (angleDifference < -PI)//Make 4 cases 2
			angleDifference += 2 * PI;
		else if (angleDifference > PI)
			angleDifference -= 2 * PI;

		return angleDifference;
	}
	bool rotate(Angle directionAngle, float rotatingSpeed, float deltaTime) {
		constexpr int multiplyingRotateFactor{ 100 };
		rotatingSpeed *= deltaTime * multiplyingRotateFactor;

		float angleDifference{ difference(directionAngle) };

		int angleSign{ angleDifference > 0 ? 1 : -1 };//Sign of the angle (1 or -1)

		if (abs(angleDifference) < rotatingSpeed) {//check if the lifeform finish rotating
			set(directionAngle);
		}
		else {
			add(rotatingSpeed * angleSign);//Rotate the correct way
		}
		if (directionAngle.get() == angle) {//If the turn is finished, we declare it as such
			return true;
		}
		return false;
	}
	bool operator==(const Angle other) const {
		return angle == other.get();
	}
	bool operator!=(const Angle other) const {
		return angle != other.get();
	}
private:
	float angle;
};

