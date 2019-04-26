#include "TextOnRect.h"


TextOnRect::TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Position<> textPosition, const Font& font, Color textColor,
	int borderSize, int textMargin, Color borderColor)
	: GraphicRect{ graphicRect }, Text{ text, textPosition, renderer, font, textColor }, position{ position }, borderSize{ borderSize }, borderColor{ borderColor }
{
}
TextOnRect::TextOnRect(Color backgroundColor, const std::string& text, SDL_Renderer* renderer, Position<> position, const Font& font, Color textColor,
	int borderSize, int textMargin, Color borderColor)
	: TextOnRect{ GraphicRect{static_cast<short>(font.getWidth(text) + 2 * borderSize + 2 * textMargin), static_cast<short>(font.getHeight() * 5 / 6 + 2 * borderSize + 2 * textMargin), backgroundColor },
	text, renderer, position, Position<>{position.x + borderSize + textMargin, position.y + borderSize + textMargin}, font, textColor, borderSize, textMargin, borderColor }
{}

void TextOnRect::render(SDL_Renderer* renderer, SDL_Rect* srcRect, SDL_Rect* dstRect) const {
	GraphicRect::renderWithoutCamera(renderer, position, dstRect);
	Text::render(renderer, srcRect, dstRect);
	//render the border if any
	if (borderSize) {
		//render the border
		SDL_SetRenderDrawColor(renderer, borderColor.red, borderColor.green, borderColor.blue, borderColor.transparency);
		//upper left to upper right
		SDL_RenderFillRect(renderer, &Rectangle{ position.x, position.y, GraphicRect::getW(), borderSize }.toSDL_Rect());
		//upper right to bottom right
		SDL_RenderFillRect(renderer, &Rectangle{ position.x + GraphicRect::getW() - borderSize, position.y, borderSize, GraphicRect::getH() }.toSDL_Rect());
		//bottom left to bottom right
		SDL_RenderFillRect(renderer, &Rectangle{ position.x, position.y + GraphicRect::getH() - borderSize, GraphicRect::getW(), borderSize }.toSDL_Rect());
		//upper left to bottom left
		SDL_RenderFillRect(renderer, &Rectangle{ position.x, position.y, borderSize, GraphicRect::getH() }.toSDL_Rect());
	}
}

TextOnRect::~TextOnRect()
{
}
