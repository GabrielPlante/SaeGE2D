#include "TextOnRect.h"


TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color textColor, const std::string& fontFileName)
	:GraphicRect{ graphicRect }, text{ text, textColor, textPosition, renderer, fontFileName }, position{ position }
{}

TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Color textColor, const std::string& fontFileName)
	: GraphicRect{ graphicRect }, text{ text, textColor, Rectangle{position, graphicRect.getW(), graphicRect.getH()}, renderer, fontFileName }, position{ position }
{}

void TextOnRect::render(SDL_Renderer* renderer) const {
	GraphicRect::renderWithoutCamera(renderer, position);
	text.render(renderer);
}

TextOnRect::~TextOnRect()
{
}
