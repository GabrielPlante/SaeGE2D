#pragma once
constexpr double PI = 3.14159265;
struct Angle
{
	Angle(double angle = 0) : angle{ angle } {
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
	double get() const { return angle; }
	double toDegree() const { return 180 * angle / PI; }
	void set(Angle angle) {
		this->angle = angle.get();
		if (angle.get() < 0 || angle.get() > 2 * PI)
			add(0);
	}
	double difference(const Angle other) const {//Result in [-PI;PI]
		double angleDifference = angle - other.get();
		if (angleDifference < -PI)//Make 4 cases 2
			angleDifference += 2 * PI;
		else if (angleDifference > PI)
			angleDifference -= 2 * PI;

		return angleDifference;
	}
	bool operator==(const Angle other) const {
		return angle == other.get();
	}

	double operator+(const Angle other) const {
		Angle newAngle{ angle };
		newAngle.add(other);
		return newAngle.get();
	}

private:
	double angle;
};

