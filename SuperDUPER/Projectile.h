#pragma once
#include <SDL.h>
#include "Camera.h"
#include "Angle.h"
#include "Item.h"
#include <vector>
#include <memory>
#include <chrono>
class Map;
class LifeForm;
class Projectile :
	public Item
{
public:
	Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<double> position);
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	virtual bool refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms, float speed, int range,
		long long deltaTime, int damage);//Return true if the projectile doesn't exist anymore
	const Position<double>& getPosition() const { return position; }
	Angle getFacingDirection() const { return facingDirection; }
	~Projectile();
private:
	Angle facingDirection;
	Position<double> position;
};

