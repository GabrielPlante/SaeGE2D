#include "InputBar.h"



InputBar::InputBar(GraphicRect graphicRect, Position<> position, Color textColor, const std::string& fontFileName)
	:graphicRect{ graphicRect }, position{ position }, textColor{ textColor }, fontFileName{ fontFileName }, font{ graphicRect.getH(), fontFileName }
{
}

void InputBar::pushBackText(const std::string& text) {
	if (!openingFrame) {
		inputText += text;
		needRendering = true;
	}
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
		openingFrame = true;
	}
}

void InputBar::close() {
	if (opened) {
		opened = false;
		textInput.reset();
	}
}

void InputBar::render(SDL_Renderer* renderer) {
	if (openingFrame)
		openingFrame = false;
	if (needRendering) {
		renderPendingText(renderer);
	}
	graphicRect.renderWithoutCamera(renderer, position);
	if (graphicText) {
		SDL_Rect sourceRect;
		sourceRect.x = font.getWidth(inputText) > graphicRect.getW() ?  font.getWidth(inputText) - graphicRect.getW(): 0;
		sourceRect.y = 0;
		sourceRect.w = font.getWidth(inputText);
		sourceRect.h = font.getHeight();
		SDL_Rect destinationRect{ Rectangle{position, graphicRect.getW(), graphicRect.getH()}.toSDL_Rect() };
		if (graphicRect.getW() > font.getWidth(inputText))
			destinationRect.w = font.getWidth(inputText);
		graphicText->render(renderer, &sourceRect, &destinationRect);
	}
}

void InputBar::renderPendingText(SDL_Renderer* renderer) {
	graphicText = std::unique_ptr<Text>{ new Text{inputText, position, renderer, font, textColor} };
	needRendering = false;
}

std::unique_ptr<Text> InputBar::clear() {
	if (inputText.size() == 0)
		return nullptr;
	inputText.clear();
	std::unique_ptr<Text> textPtr;
	graphicText.swap(textPtr);
	return textPtr;
}
