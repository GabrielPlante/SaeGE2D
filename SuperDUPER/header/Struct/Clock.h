#pragma once
#include <chrono>
struct Clock
{
public:
	Clock() {
		lastTime = std::chrono::high_resolution_clock::now();
	}
	long long getTime() const { return static_cast<long long>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - lastTime).count()*static_cast<double>(timeScale)); }
	long long resetTime() {
		auto time = getTime();
		lastTime = std::chrono::high_resolution_clock::now();
		return time;
	}
	void setTimeScale(float newTimeScale) { timeScale = newTimeScale; }
	float getTimeScale() const { return timeScale; }
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
	static float timeScale;
};
