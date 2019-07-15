#pragma once
#include <vector>
#include <queue>
#include "TextOnRect.h"
//Used to render several line of text in an area
class TextArea
	:public GraphicRect
{
private:
	std::vector<std::unique_ptr<Text>> textList;
	Position<> position;
	std::queue<std::string> textToRender;
	std::queue<Color> textColor;
	Font font;

	//Add all the text stocked this frame to the text area
	void addPendingText(SDL_Renderer* renderer);

public:
	TextArea(GraphicRect graphicRect, const Position<>& position, int textHeight, const std::string& fontFileName = "mainFont.ttf");

	//Add text in form of the Text object
	void addText(std::unique_ptr<Text> text) { textList.push_back(std::move(text)); }

	//Add text with an std::string
	void addText(const std::string& text, const Color& color = Color{ 0, 0, 0 }) { textToRender.push(text); textColor.push(color); }

	//Render the textArea
	void render(SDL_Renderer* renderer);
};

