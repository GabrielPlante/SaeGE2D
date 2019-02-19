#include "Character.h"



Character::Character(int x, int y, Color color)
	:LifeForm(x, y, 300, 500, 10) {
	shape = std::unique_ptr<Renderable>{ new Circle(x, y, radius, color) };
}

void Character::render(SDL_Renderer* renderer, const Camera& camera) const {
	if (isAlive()) {
		Entity::render(renderer, camera);
		LifeForm::render(renderer, camera);
	}
}

bool Character::refresh(const Map& map, const std::vector<std::unique_ptr<LifeForm>>& lifeForms) {
	LifeForm::refresh(map, lifeForms);
	return false;
}

Character::~Character()
{
}
