#include "TextOnRect.h"


TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Position<> textPosition, const Font& font, Color textColor)
	: GraphicRect{ graphicRect }, Text{ text, textColor, textPosition, renderer, font }, position{ position }
{}
TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, const Font& font, Color textColor)
	: GraphicRect{ graphicRect }, Text{ text, textColor, position, renderer, font }, position{ position }
{}

void TextOnRect::render(SDL_Renderer* renderer) const {
	GraphicRect::renderWithoutCamera(renderer, position);
	Text::render(renderer);
}

TextOnRect::~TextOnRect()
{
}
