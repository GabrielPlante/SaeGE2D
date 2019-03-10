#pragma once
#include "GraphicRect.h"
#include "Text.h"
class TextOnRect
{
public:
	TextOnRect(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	//Text on rect with the text in all the rect
	TextOnRect(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	void render(SDL_Renderer* renderer) const;
	~TextOnRect();
private:
	GraphicRect graphicRect;
	Text text;
	Position<> position;
};

