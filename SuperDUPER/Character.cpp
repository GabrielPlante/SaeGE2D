#include "Character.h"



Character::Character(int x, int y, Color color)
	:LifeForm(x, y, 300, 500) {
	shape = std::unique_ptr<Renderable>{ new Circle(x, y, radius, color) };
}

void Character::render(SDL_Renderer* renderer, const Camera& camera) {
	if (isAlive()) {
		Entity::render(renderer, camera);
		LifeForm::render(renderer, camera);
	}
}

bool Character::refresh() {
	LifeForm::refresh();
	return false;
}

Character::~Character()
{
}
