/*
* The console
* It is a singleton (to be implemented)
*/
#pragma once
#include "Rectangle.h"
#include "InputBar.h"
#include "TextToCommand.h"
#include "TextArea.h"
#include <memory>
class CommandList;
class GameLoop;
class Console
	:public InputBar, public TextArea
{
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
public:
	Console(Rectangle rectangle, Color backgroundColor = Color{ 100, 100, 100 }, Color borderColor = Color{ 200, 200, 200 },
		int borderSize = 3, int textHeight = 20, int textMargin = 3);

	//Render the console on the screen
	void render(SDL_Renderer* renderer);

	//Get the command that the user typed in the console
	TextToCommand getCommand() const { return TextToCommand{ getInputText() }; }

	//Used when the user press enter
	void enterText();

	//Used to treat the input text as a command
	void enterCommand(const CommandList& commandList, GameLoop* gameLoop);
};

