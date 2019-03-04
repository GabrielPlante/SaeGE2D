#include "BasicArrow.h"



BasicArrow::BasicArrow(Angle facingDirection, Position<float> position)
	:Projectile{ "Basic Arrow", 5, facingDirection, position }
{
}

void BasicArrow::render(SDL_Renderer* renderer, const Camera& camera) const {
	constexpr int length = 50;
	Position<> rear{ camera.absoluteToRelative(static_cast<long>(-cos(getFacingDirection().get()) * length+getPosition().x), static_cast<long>(-sin(getFacingDirection().get()) * length+getPosition().y)) };
	Position<> front{ camera.absoluteToRelative(static_cast<long>(getPosition().x), static_cast<long>(getPosition().y)) };
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	SDL_RenderDrawLine(renderer, rear.x, rear.y, front.x, front.y);
}

std::unique_ptr<Projectile> BasicArrow::clone(Angle facingDirection, Position<float> position) const {
	return std::unique_ptr<Projectile> {new BasicArrow{ facingDirection, position }};
}
	
BasicArrow::~BasicArrow()
{
}
