#pragma once
#include "GraphicRect.h"
#include "Text.h"
class TextOnRect
	:public GraphicRect, public Text
{
public:
	TextOnRect(GraphicRect graphicRect, const std::string& text, SDL_Renderer* renderer, Position<> position, Position<> textPosition, const Font& font, Color textColor = Color{ 0, 0, 0 },
		int borderSize = 0, int textMargin = 0, Color borderColor = Color{ 200, 200, 200 });
	//Text on rect with the text taking all the rectangle
	TextOnRect(Color backgroundColor, const std::string& text, SDL_Renderer* renderer, Position<> position, const Font& font, Color textColor = Color{ 0, 0, 0 },
		int borderSize = 0, int textMargin = 0, Color borderColor = Color{ 200, 200, 200 });
	void render(SDL_Renderer* renderer, SDL_Rect* srcRect = nullptr, SDL_Rect* dstRect = nullptr) const;
	const Position<>& getPosition() const { return position; }
	~TextOnRect();
private:
	Position<> position;
	int borderSize;
	Color borderColor;
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
