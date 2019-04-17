#include "Text.h"


Text::Text(const std::string& text, Color color, Rectangle position, SDL_Renderer* renderer, const std::string& fontFileName)
	:color{ color }, position{ position }
{
	//Load the font with a good size
	Font font{ static_cast<short>(position.h), fontFileName };
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
	SDL_RenderCopy(renderer, texture, NULL, &position.toSDL_Rect());
}

Text::~Text()
{
	SDL_DestroyTexture(texture);
}
