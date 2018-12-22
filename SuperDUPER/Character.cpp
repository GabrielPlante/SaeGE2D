#include "Character.h"



Character::Character(int x, int y, Color color)
	:LifeForm(x, y, 300, 500) {
	shape = std::unique_ptr<Renderable>{ new Circle(x, y, 5, color) };
}

bool Character::refresh() {
	LifeForm::refresh();
	return false;
}

Character::~Character()
{
}
