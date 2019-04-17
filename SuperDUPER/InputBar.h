#pragma once
#include "TextOnRect.h"
class InputBar
{
public:
	InputBar(GraphicRect graphicRect, Position<> position, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	void render(SDL_Renderer* renderer);
	void addText(const std::string& text);
	void setText(const std::string& text);
	void popText();
	const std::string& getInputText() const { return inputText; }
	~InputBar();
private:
	bool needRendering = false;
	std::string inputText;
	std::unique_ptr<TextOnRect> graphicText;
	GraphicRect graphicRect;
	Position<> position;
	Color textColor;
	std::string fontFileName;
};

