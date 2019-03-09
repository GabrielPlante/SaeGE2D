#include "TextOnRect.h"



TextOnRect::TextOnRect(GraphicRect graphicRect, std::string text, Color textColor, Rectangle textPosition, SDL_Renderer* renderer, const Font& font, Position<> position)
	:graphicRect{ graphicRect }, text{ text, textColor, textPosition, renderer, font }, position{ position }
{
}

void TextOnRect::render(SDL_Renderer* renderer) const {
	graphicRect.renderWithoutCamera(renderer, position);
	text.render(renderer);
}

TextOnRect::~TextOnRect()
{
}
