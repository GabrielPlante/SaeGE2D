#include "Console.h"



Console::Console(Rectangle rectangle, Color backgroundColor, Color borderColor, int borderSize, int textHeight)
	:rectangle{ rectangle }, backgroundColor{ backgroundColor }, borderColor{ borderColor }, borderSize{ borderSize }, textHeight{ textHeight }
{
}

void Console::open() {
	opened = true;
	textInput = std::unique_ptr<TextInput>{ new TextInput() };
}

void Console::close() {
	opened = false;
	textInput.reset();
}

void Console::render(SDL_Renderer* renderer) const {
	if (opened) {
		//First render the background
		SDL_SetRenderDrawColor(renderer, backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.transparency);
		SDL_RenderFillRect(renderer, &rectangle.toSDL_Rect());
		//Then render the boarder
		SDL_SetRenderDrawColor(renderer, borderColor.red, borderColor.green, borderColor.blue, borderColor.transparency);
		//upper left to upper right
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y, rectangle.w, borderSize }.toSDL_Rect());
		//upper right to bottom right
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x + rectangle.w- borderSize, rectangle.y, borderSize, rectangle.h }.toSDL_Rect());
		//bottom left to bottom right
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y + rectangle.h - borderSize, rectangle.w, borderSize }.toSDL_Rect());
		//upper left to bottom left
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y, borderSize, rectangle.h }.toSDL_Rect());
		if (inputBar)
			inputBar->render(renderer);
	}
}

void Console::setInputText(const std::string& text, SDL_Renderer* renderer) {
	constexpr int charWidth{ 10 };
	inputText = text;
	inputBar = std::unique_ptr<TextOnRect>{ new TextOnRect{GraphicRect{static_cast<short>(rectangle.w - 2 * borderSize), static_cast<short>(textHeight), backgroundColor},
		text, renderer, Position<>{rectangle.x + borderSize, rectangle.y + rectangle.h - borderSize - textHeight},
		Rectangle{rectangle.x + borderSize, rectangle.y + rectangle.h - borderSize - textHeight, static_cast<const int>(text.size()) * charWidth, textHeight}} };
}

void Console::addInputText(const std::string& text, SDL_Renderer* renderer) {
	setInputText(inputText + text, renderer);
}

Console::~Console()
{
}
