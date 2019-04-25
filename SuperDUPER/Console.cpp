#include "Console.h"



Console::Console(Rectangle rectangle, Color backgroundColor, Color borderColor, int borderSize, int textHeight, int textMargin)
	:InputBar{ GraphicRect{static_cast<short>(rectangle.w - 2 * borderSize - 2*textMargin), static_cast<short>(textHeight), backgroundColor},
		Position<>{rectangle.x + borderSize+textMargin, rectangle.y + rectangle.h - borderSize - textHeight-textMargin} },
	TextArea{ GraphicRect{static_cast<short>(rectangle.w - 2 * borderSize - 2 * textMargin), static_cast<short>(rectangle.h - 4 * textHeight - 3 * textMargin), Color{0, 0, 0, 0}},
		Position<>{rectangle.x + textMargin + borderSize, rectangle.y + textMargin + borderSize} },
	rectangle{ rectangle }, backgroundColor{ backgroundColor }, borderColor{ borderColor }, borderSize{ borderSize }, textHeight{ textHeight }, textMargin{ textMargin }
{}

void Console::render(SDL_Renderer* renderer) {
	if (isOpened()) {
		//First render the background
		SDL_SetRenderDrawColor(renderer, backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.transparency);
		SDL_RenderFillRect(renderer, &rectangle.toSDL_Rect());
		//Render the background
		InputBar::render(renderer);
		if (needToPressEnter)
			enterText();
		TextArea::render(renderer, textHeight);
		//Then render the boarder
		SDL_SetRenderDrawColor(renderer, borderColor.red, borderColor.green, borderColor.blue, borderColor.transparency);
		//upper left to upper right
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y, rectangle.w, borderSize }.toSDL_Rect());
		//upper right to bottom right
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x + rectangle.w - borderSize, rectangle.y, borderSize, rectangle.h }.toSDL_Rect());
		//bottom left to bottom right
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y + rectangle.h - borderSize, rectangle.w, borderSize }.toSDL_Rect());
		//upper left to bottom left
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y, borderSize, rectangle.h }.toSDL_Rect());
		//The bar above the input bar
		SDL_RenderFillRect(renderer, &Rectangle{ rectangle.x, rectangle.y + rectangle.h - borderSize*2 - textHeight-textMargin*2, rectangle.w, borderSize }.toSDL_Rect());
	}
}

void Console::enterText() {
	if (InputBar::getInputText().size() > 0 && !doesNeedRendering()) {
		TextArea::addText(InputBar::clear());
		needToPressEnter = false;
	}
	else if (doesNeedRendering())
		needToPressEnter = true;
}

Console::~Console()
{
}
