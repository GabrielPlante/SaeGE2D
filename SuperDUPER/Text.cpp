#include "Text.h"
#include <iostream>


Text::Text(std::string text, Color color, Rectangle position, SDL_Renderer* renderer, const Font& font)
	:text{ text }, color{ color }, position{ position }
{
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
	if (SDL_RenderCopy(renderer, texture, NULL, &position.toSDL_Rect()) < 0)
		std::cout << "OOOO " << SDL_GetError() << std::endl;
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}
