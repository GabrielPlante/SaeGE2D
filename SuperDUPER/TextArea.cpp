#include "TextArea.h"



TextArea::TextArea(GraphicRect graphicRect, const Position<>& position, int textHeight, const std::string& fontFileName)
	:GraphicRect{ graphicRect }, position{ position }, font{ textHeight, fontFileName }
{
}

void TextArea::render(SDL_Renderer* renderer) {
	addPendingText(renderer);
	for (int i = textList.size() - 1; i >= 0; i--) {
		Rectangle rect{ position.x, position.y + GraphicRect::getH() - font.getHeight() * (static_cast<long>(textList.size()) - i), textList[i]->getRect().w, textList[i]->getRect().h };
		if (rect.y < position.y)
			break;
		textList[i]->render(renderer, nullptr, &rect.toSDL_Rect());
	}
}

void TextArea::addPendingText(SDL_Renderer* renderer) {
	while (!textToRender.empty()) {
		addText(std::unique_ptr<Text>{new Text{ textToRender.front(), Position<>{0, 0}, renderer, font, textColor.front() }});
		textToRender.pop();
		textColor.pop();
	}
}
