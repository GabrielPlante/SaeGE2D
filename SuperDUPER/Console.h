#pragma once
#include "Rectangle.h"
#include "TextInput.h"
#include "TextOnRect.h"
#include <memory>
class Console
{
public:
	Console(Rectangle rectangle, Color backgroundColor = Color{ 50, 50, 50 }, Color borderColor = Color{ 200, 200, 200 },
		int borderSize = 3, int textHeight = 20);
	void open();
	void close();
	void render(SDL_Renderer* renderer) const;
	void setInputText(const std::string& text, SDL_Renderer* renderer);
	void addInputText(const std::string& text, SDL_Renderer* renderer);
	bool isOpened() const { return opened; }
	~Console();
private:
	Rectangle rectangle;
	std::unique_ptr<TextInput> textInput;
	bool opened = false;
	Color backgroundColor;
	Color borderColor;
	int borderSize;
	int textHeight;
	std::unique_ptr<TextOnRect> inputBar;
	std::string inputText = "";
};

