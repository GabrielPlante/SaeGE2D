#include "Text.h"


Text::Text(const std::string& text, const Color& color, const Position<>& position, SDL_Renderer* renderer, const Font& font)
	:color{ color }
{
	int textWidth;
	TTF_SizeText(font.getFont(), text.c_str(), &textWidth, nullptr);
	rect = Rectangle{ position, textWidth, static_cast<int>(font.getFontSize()) };
	//Create the surface
	SDL_Surface* surfaceText{ TTF_RenderText_Solid(font.getFont(), text.c_str(), color.toSDLColor()) };
	if (!surfaceText)
		throw std::runtime_error("Could not create SDL_Surface !");
	//Transform the surface into a texture
	texture = SDL_CreateTextureFromSurface(renderer, surfaceText);
	if (!texture)
		throw std::runtime_error("Could not create SDL_Texture !");
	//Release the surface
	SDL_FreeSurface(surfaceText);
}

void Text::render(SDL_Renderer* renderer) const {
	SDL_RenderCopy(renderer, texture, NULL, &rect.toSDL_Rect());
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}
