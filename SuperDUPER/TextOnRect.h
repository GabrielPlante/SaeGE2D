#pragma once
#include "GraphicRect.h"
#include "Text.h"
class TextOnRect
{
public:
	TextOnRect(GraphicRect graphicRect, std::string text, Color textColor, Rectangle textPosition, SDL_Renderer* renderer, const Font& font, Position<> position);
	void render(SDL_Renderer* renderer) const;
	~TextOnRect();
private:
	GraphicRect graphicRect;
	Text text;
	Position<> position;
};

