#include "Button.h"



Button::Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color textColor, const std::string& fontFileName)
	:TextOnRect{ graphicRect, text, renderer, position, textPosition, textColor, fontFileName }
{
}

Button::Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Color textColor, const std::string& fontFileName)
	: TextOnRect{ graphicRect, text, renderer, position, textColor, fontFileName }
{}

Button::~Button()
{
}
