#pragma once
#include "TextOnRect.h"
#include "../TextInput.h"
class InputBar
{
public:
	InputBar(GraphicRect graphicRect, Position<> position, Color textColor = Color{ 0, 0, 0 }, const std::string& fontFileName = "mainFont.ttf");
	void pushBackText(const std::string& text);
	void setText(const std::string& text);
	void popText();
	void open();
	void close();
	void render(SDL_Renderer* renderer);
	void renderPendingText(SDL_Renderer* renderer);
	bool isOpened() const { return opened; }
	bool doesNeedRendering() const { return needRendering; }
	const std::string& getInputText() const { return inputText; }
	std::unique_ptr<Text> clear();
	~InputBar();
private:
	bool needRendering = false;
	std::string inputText;
	Font font;
	//The actual texture rendered
	std::unique_ptr<Text> graphicText;
	//Those are needed to recreate the texture each time a character is typed
	GraphicRect graphicRect;
	Position<> position;
	Color textColor;
	std::string fontFileName;
	std::unique_ptr<TextInput> textInput;
	bool opened = false;
	//To tackle the "open letter input" issue
	bool openingFrame = false;
};

