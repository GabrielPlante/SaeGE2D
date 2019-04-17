#pragma once
#include "GraphicRect.h"
#include "Text.h"
class TextOnRect
	:public GraphicRect
{
public:
	TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Rectangle textPosition, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	//Text on rect with the text in all the rect
	TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	void render(SDL_Renderer* renderer) const;
	const Position<>& getPosition() const { return position; }
	~TextOnRect();
private:
	Text text;
	Position<> position;
};

inline bool operator<(const TextOnRect& left, const TextOnRect& right) {
	if (left.getPosition().y != right.getPosition().y)
		return left.getPosition().y < right.getPosition().y;
	if (left.getPosition().x != right.getPosition().x)
		return left.getPosition().x < right.getPosition().x;
	if (left.getH() != right.getH())
		return left.getH() < right.getH();
	return left.getW() < right.getW();
}
