#pragma once
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
		float angleDifference = angle - other.get();
		if (angleDifference < -PI)//Make 4 cases 2
			angleDifference += 2 * PI;
		else if (angleDifference > PI)
			angleDifference -= 2 * PI;

		return angleDifference;
	}
	bool operator==(const Angle other) const {
		return angle == other.get();
	}
private:
	float angle;
};

