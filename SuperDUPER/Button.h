#pragma once
#include "TextOnRect.h"
class Button :
	public TextOnRect
{
public:
	Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color offSetOnHovering = Color{ 10, 10, 10 },
		Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Color offSetOnHovering = Color{ 30, 30, 30 }, Color textColor = Color{ 0, 0, 0 },
		const std::string& fontFileName = "mainFont.ttf");
	//Take the mouse position and check and apply effect
	bool checkIfHovering(const Position<>& mousePosition);
	//Apply effect of the mouse overing
	void onHovering();
	void unHovering();
	~Button();
private:
	Color offSetOnHovering;
	bool isHovering = false;
};

