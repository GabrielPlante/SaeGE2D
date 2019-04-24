#include "Text.h"


Text::Text(const std::string& text, const Position<>& position, SDL_Renderer* renderer, const Font& font, const Color& color)
	:color{ color }
{
	int textWidth{ font.getWidth(text) };
	rect = Rectangle{ position, font.getWidth(text), font.getHeight() };
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
