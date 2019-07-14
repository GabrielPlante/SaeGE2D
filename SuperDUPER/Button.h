#pragma once
#include "TextOnRect.h"
class Button :
	public TextOnRect
{
public:
	Button(GraphicRect graphicRect, std::string text, SDL_Renderer* renderer, Position<> position, Position<> textPosition,
		const Font& font, Color offSetOnHovering = Color{ 10, 10, 10 }, Color textColor = Color{ 0, 0, 0 });
	Button(Color backgroundColor, std::string text, SDL_Renderer* renderer, Position<> position, const Font& font, Color offSetOnHovering = Color{ 30, 30, 30 },
		Color textColor = Color{ 0, 0, 0 });
	//Take the mouse position and check and apply effect and return true if the mouse is hovering
	bool checkIfHovering(const Position<>& mousePosition);
	//Apply effect of the mouse overing
	void onHovering();
	void unHovering();
	~Button();
private:
	Color offSetOnHovering;
	bool isHovering = false;
};
