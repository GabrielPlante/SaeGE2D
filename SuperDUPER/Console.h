#pragma once
#include "Rectangle.h"
#include "InputBar.h"
#include "TextToCommand.h"
#include <memory>
class Console
	:public InputBar
{
public:
	Console(Rectangle rectangle, Color backgroundColor = Color{ 50, 50, 50 }, Color borderColor = Color{ 200, 200, 200 },
		int borderSize = 3, int textHeight = 20, int textMargin = 3);
	void render(SDL_Renderer* renderer);
	TextToCommand getCommand() const { return TextToCommand{ getInputText() }; }
	~Console();
private:
	Rectangle rectangle;
	std::unique_ptr<TextInput> textInput;
	Color backgroundColor;
	Color borderColor;
	int borderSize;
	int textHeight;
	int textMargin;
};

