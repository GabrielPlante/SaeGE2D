#pragma once
#include <vector>
#include "TextOnRect.h"
//Used to render several line of text in an area
class TextArea
	:public GraphicRect
{
public:
	TextArea(GraphicRect graphicRect, const Position<>& position);
	void addText(std::unique_ptr<Text> text) { textList.push_back(std::move(text)); }
	void render(SDL_Renderer* renderer, int textHeight) const;
	~TextArea();
private:
	std::vector<std::unique_ptr<Text>> textList;
	Position<> position;
};

