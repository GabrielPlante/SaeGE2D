#pragma once
#include "TextOnRect.h"
class Button :
	public TextOnRect
{
public:
	Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	~Button();
};

