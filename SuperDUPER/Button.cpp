#include "Button.h"



Button::Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color offSetOnHovering, Color textColor, const std::string& fontFileName)
	:TextOnRect{ graphicRect, text, renderer, position, textPosition, textColor, fontFileName }, offSetOnHovering{ offSetOnHovering }
{
}

Button::Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Color offSetOnHovering, Color textColor, const std::string& fontFileName)
	: TextOnRect{ graphicRect, text, renderer, position, textColor, fontFileName }, offSetOnHovering{ offSetOnHovering }
{}

bool Button::checkIfHovering(const Position<>& mousePosition) {
	if (!isHovering && pointIsIn(mousePosition)) {
		onHovering();
		isHovering = true;
		return true;
	}
	else if (isHovering && !pointIsIn(mousePosition)) {
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
