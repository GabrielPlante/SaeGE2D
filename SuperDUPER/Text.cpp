#include "Text.h"



Text::Text(std::string text, Color color, Rectangle position, SDL_Renderer* renderer, const Font& font)
	:text{ text }, color{ color }, position{ position }
{
	//Create the surface
	SDL_Surface* surfaceText{ TTF_RenderText_Solid(font.getFont(), text.c_str(), color.toSDLColor()) };
	//Transform the surface into a texture
	texture = SDL_CreateTextureFromSurface(renderer, surfaceText);
	//Release the surface
	SDL_FreeSurface(surfaceText);
}

void Text::render(SDL_Renderer* renderer) const {
	SDL_RenderCopy(renderer, texture, NULL, &position.toSDL_Rect());
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}
