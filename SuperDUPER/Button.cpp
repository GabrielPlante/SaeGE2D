#include "Button.h"



Button::Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Position<> textPosition, const Font& font, Color offSetOnHovering, Color textColor)
	:TextOnRect{ graphicRect, text, renderer, position, textPosition, font, textColor }, offSetOnHovering{ offSetOnHovering }
{
}

Button::Button(Color backgroundColor, std::string text, SDL_Renderer* renderer, Position<> position, const Font& font, Color offSetOnHovering, Color textColor)
	: TextOnRect{ backgroundColor, text, renderer, position, font, textColor }, offSetOnHovering{ offSetOnHovering }
{}

bool Button::checkIfHovering(const Position<>& mousePosition) {
	if (!isHovering && pointIsIn(mousePosition, getPosition())) {
		onHovering();
		isHovering = true;
		return true;
	}
	else if (isHovering && !pointIsIn(mousePosition, getPosition())) {
		unHovering();
		isHovering = false;
	}
	return false;
}

void Button::onHovering() {
	changeColor(Color{ getColor().red + offSetOnHovering.red, getColor().green + offSetOnHovering.green, getColor().blue + offSetOnHovering.blue, getColor().transparency + offSetOnHovering.transparency });
}

void Button::unHovering() {
	changeColor(Color{ getColor().red - offSetOnHovering.red, getColor().green - offSetOnHovering.green, getColor().blue - offSetOnHovering.blue, getColor().transparency - offSetOnHovering.transparency });
}

Button::~Button()
{
}
