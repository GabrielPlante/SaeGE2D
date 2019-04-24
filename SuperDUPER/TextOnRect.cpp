#include "TextOnRect.h"


TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Position<> textPosition, const Font& font, Color textColor)
	: GraphicRect{ graphicRect }, Text{ text, textPosition, renderer, font, textColor }, position{ position }
{
	graphicRect.setH(graphicRect.getH() * 5 / 6);
}
TextOnRect::TextOnRect(Color backgroundColor, const std::string& text, SDL_Renderer* renderer, Position<> position, const Font& font, Color textColor)
	: GraphicRect{ static_cast<short>(font.getWidth(text)), static_cast<short>(font.getHeight()*5/6), backgroundColor }, Text{ text, position, renderer, font, textColor }, position{ position }
{}

void TextOnRect::render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* dstRect) const {
	GraphicRect::renderWithoutCamera(renderer, position, dstRect);
	Text::render(renderer, srcRect, dstRect);
}

TextOnRect::~TextOnRect()
{
}
