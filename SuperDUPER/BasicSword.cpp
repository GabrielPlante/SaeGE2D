#include "BasicSword.h"
#include "LifeForm.h"


BasicSword::BasicSword()
	:MeleeWeapon{ "Basic Sword", 100, 100, 30, 0.5f }
{
}

void BasicSword::render(SDL_Renderer* renderer, const Camera& camera, const LifeForm& owner) const {
	if (camera.isInCamera(Rectangle{ static_cast<int>(owner.getPosition().x), static_cast<int>(owner.getPosition().y), 1, 1 })) {
		Position<> front{ camera.absoluteToRelative(static_cast<long>(owner.getPosition().x) + owner.getRadius(), static_cast<long>(owner.getPosition().y) + owner.getRadius()) };
		Position<> back{ camera.absoluteToRelative(static_cast<long>(owner.getPosition().x) - owner.getRadius(), static_cast<long>(owner.getPosition().y) - owner.getRadius()) };
		SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);
		SDL_RenderDrawLine(renderer, front.x, front.y, back.x, back.y);
	}
}


BasicSword::~BasicSword()
{
}
