#pragma once
#include <vector>
#include <queue>
#include "TextOnRect.h"
//Used to render several line of text in an area
class TextArea
	:public GraphicRect
{
public:
	TextArea(GraphicRect graphicRect, const Position<>& position, int textHeight, const std::string& fontFileName = "mainFont.ttf");
	void addText(std::unique_ptr<Text> text) { textList.push_back(std::move(text)); }
	void addText(const std::string& text, const Color& color = Color{ 0, 0, 0 }) { textToRender.push(text); textColor.push(color); }
	void render(SDL_Renderer* renderer);
	void addPendingText(SDL_Renderer* renderer);
	~TextArea();
private:
	std::vector<std::unique_ptr<Text>> textList;
	Position<> position;
	std::queue<std::string> textToRender;
	std::queue<Color> textColor;
	Font font;
};

