#include "../../header/Entities/Character.h"



Character::Character(int x, int y, Color color)
	:LifeForm(static_cast<float>(x), static_cast<float>(y), 300, 500, 10) {
	shape = std::unique_ptr<Renderable>{ new Circle(radius, color) };
}

void Character::render(SDL_Renderer* renderer, const Camera& camera) const {
	//if (isAlive()) {
		LifeForm::render(renderer, camera);
	//}
}

bool Character::refresh(const Map& map, const LifeFormList& lifeForms, float deltaTime, const std::vector<float>& gameValues) {
	if (LifeForm::refresh(map, lifeForms, deltaTime, gameValues))
		return true;
	return false;
}

Character::~Character()
{
}