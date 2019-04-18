#include "InputBar.h"



InputBar::InputBar(GraphicRect graphicRect, Position<> position, Color textColor, const std::string& fontFileName)
	:graphicRect{ graphicRect }, position{ position }, textColor{ textColor }, fontFileName{ fontFileName }
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
		constexpr int charWidth{ 10 };
		const int textWidth{ min(static_cast<int>(inputText.size()*charWidth), static_cast<int>(graphicRect.getW())) };
		graphicText = std::unique_ptr<TextOnRect>{ new TextOnRect{graphicRect, inputText, renderer, position,
			Rectangle{position.x, position.y, textWidth, graphicRect.getH()}, textColor, fontFileName} };
		needRendering = false;
	}
	if (graphicText)
		graphicText->render(renderer);
}

InputBar::~InputBar()
{
}
