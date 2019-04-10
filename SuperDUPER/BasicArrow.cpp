#include "BasicArrow.h"



BasicArrow::BasicArrow(Angle facingDirection, Position<float> position, unsigned short speed,
	unsigned short range, float damageMultiplier, unsigned short mass, float sharpness, int ownerId)
	:Projectile{ "Basic Arrow", 5, facingDirection, position, speed, range, damageMultiplier, mass, sharpness, ownerId }
{
}

void BasicArrow::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	constexpr int length = 50;
	Position<> rear{ camera.absoluteToRelative(static_cast<long>(-cos(getFacingDirection().get()) * length+getPosition().x), static_cast<long>(-sin(getFacingDirection().get()) * length+getPosition().y)) };
	Position<> front{ camera.absoluteToRelative(static_cast<long>(getPosition().x), static_cast<long>(getPosition().y)) };
	SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
	SDL_RenderDrawLine(renderer, rear.x, rear.y, front.x, front.y);
}

std::unique_ptr<WeaponAttack> BasicArrow::clone(Angle facingDirection, Position<float> position, int ownerId) const {
	return std::unique_ptr<WeaponAttack> {new BasicArrow{ facingDirection, position, getSpeed(), getRange(),
		getDamageMultiplier(), getMass(), getSharpness(), ownerId }};
}

BasicArrow::~BasicArrow()
{
}
