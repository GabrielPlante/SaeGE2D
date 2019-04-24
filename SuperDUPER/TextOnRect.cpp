#include "TextOnRect.h"


TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Position<> textPosition, const Font& font, Color textColor)
	: GraphicRect{ graphicRect }, Text{ text, textPosition, renderer, font, textColor }, position{ position }
{}
TextOnRect::TextOnRect(Color backgroundColor, const std::string& text, SDL_Renderer* renderer, Position<> position, const Font& font, Color textColor)
	: GraphicRect{ static_cast<short>(font.getWidth(text)), static_cast<short>(font.getHeight()), backgroundColor }, Text{ text, position, renderer, font, textColor }, position{ position }
{}

void TextOnRect::render(SDL_Renderer* renderer) const {
	GraphicRect::renderWithoutCamera(renderer, position);
	Text::render(renderer);
}

TextOnRect::~TextOnRect()
{
}
