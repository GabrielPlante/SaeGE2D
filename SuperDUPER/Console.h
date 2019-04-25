#pragma once
#include "Rectangle.h"
#include "InputBar.h"
#include "TextToCommand.h"
#include "TextArea.h"
#include <memory>
class Console
	:public InputBar, public TextArea
{
public:
	Console(Rectangle rectangle, Color backgroundColor = Color{ 50, 50, 50 }, Color borderColor = Color{ 200, 200, 200 },
		int borderSize = 3, int textHeight = 20, int textMargin = 3);
	void render(SDL_Renderer* renderer);
	TextToCommand getCommand() const { return TextToCommand{ getInputText() }; }
	//Used when the user press enter
	void enterText();
	~Console();
private:
	Rectangle rectangle;
	std::unique_ptr<TextInput> textInput;
	Color backgroundColor;
	Color borderColor;
	int borderSize;
	int textHeight;
	int textMargin;
	//This is used to prevent returning a string with a missing character if the user type a letter and at the same time press enter
	bool needToPressEnter = false;
};

