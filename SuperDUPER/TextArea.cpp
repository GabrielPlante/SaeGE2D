#include "TextArea.h"



TextArea::TextArea(GraphicRect graphicRect, const Position<>& position)
	:GraphicRect{ graphicRect }, position{ position }
{
}

void TextArea::render(SDL_Renderer* renderer, int textHeight) const {
	for (int i = 0; i != textList.size(); i++) {
		SDL_Rect destination;
		destination.x = position.x;
		destination.y = position.y + textHeight * i;
		destination.w = textList[i]->getRect().w;
		destination.h = textList[i]->getRect().h;
		textList[i]->render(renderer, nullptr, &destination);
	}
}

TextArea::~TextArea()
{
}
