#include "InputBar.h"



InputBar::InputBar(GraphicRect graphicRect, Position<> position, Color textColor, const std::string& fontFileName)
	:graphicRect{ graphicRect }, position{ position }, textColor{ textColor }, fontFileName{ fontFileName }, font{ graphicRect.getH(), fontFileName }
{
}

void InputBar::addText(const std::string& text) {
	inputText += text;
	needRendering = true;
}

void InputBar::setText(const std::string& text) {
	inputText = text;
	needRendering = true;
}

void InputBar::popText() {
	if (inputText.size() > 0) {
		inputText.pop_back();
		if (inputText.size() == 0) {
			graphicText.reset();
			needRendering = false;
		}
		else
			needRendering = true;
	}
}

void InputBar::open() {
	if (!opened) {
		opened = true;
		textInput = std::unique_ptr<TextInput>{ new TextInput() };
	}
}

void InputBar::close() {
	if (opened) {
		opened = false;
		textInput.reset();
	}
}

void InputBar::render(SDL_Renderer* renderer) {
	if (needRendering) {
		int charWidth;
		TTF_SizeText(font.getFont(), inputText.c_str(), &charWidth, nullptr);
		const int textWidth{ min(static_cast<int>(charWidth), static_cast<int>(graphicRect.getW())) };
		graphicText = std::unique_ptr<TextOnRect>{ new TextOnRect{graphicRect.getColor(), inputText, renderer, position, font, textColor} };
		needRendering = false;
	}
	if (graphicText)
		graphicText->render(renderer);
}

InputBar::~InputBar()
{
}
