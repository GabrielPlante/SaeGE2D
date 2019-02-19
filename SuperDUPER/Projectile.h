#pragma once
#include <SDL.h>
#include "Camera.h"
#include "Angle.h"
#include "Item.h"
#include <vector>
#include <memory>
#include <chrono>
#include "Movement.h"
class Map;
class LifeForm;
class Projectile :
	public Item
{
public:
	Projectile(const std::string& name, int encumbrance, Angle facingDirection, Position<float> position);
	virtual void render(SDL_Renderer* renderer, const Camera& camera) const = 0;
	virtual bool refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms, float speed, int range,
		float deltaTime, int damage);//Return true if the projectile doesn't exist anymore
	const Position<float>& getPosition() const { return movement.getPosition(); }
	Angle getFacingDirection() const { return movement.getFacingDirection(); }
	~Projectile();
private:
	Movement movement;
	Position<float> startingPosition;
};

