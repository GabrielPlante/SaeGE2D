#include "InputBar.h"
#include <iostream>



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
		graphicText = std::unique_ptr<TextOnRect>{ new TextOnRect{graphicRect.getColor(), inputText, renderer, position, font, textColor} };
		needRendering = false;
	}
	if (graphicText) {
		SDL_Rect sourceRect;
		sourceRect.x = graphicText->getW() > graphicRect.getW() ?  graphicText->getW() - graphicRect.getW(): 0;
		sourceRect.y = 0;
		sourceRect.w = graphicText->getW();
		sourceRect.h = graphicText->getH();
		SDL_Rect destinationRect{ Rectangle{position, graphicRect.getW(), graphicRect.getH()}.toSDL_Rect() };
		if (graphicRect.getW() > graphicText->getW())
			destinationRect.w = graphicText->getW();
		graphicText->render(renderer, &sourceRect, &destinationRect);
	}
}

InputBar::~InputBar()
{
}
