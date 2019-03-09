#pragma once
#include <string>
#include <SDL.h>
#include "Font.h"
#include "Color.h"
#include "Rectangle.h"
class Text
{
public:
	Text(std::string text, Color color, Rectangle position, SDL_Renderer* renderer, const Font& font);
	void render(SDL_Renderer* renderer) const;
	~Text();
private:
	Text(const Text&) {}
	std::string text;
	Color color;
	Rectangle position;
	SDL_Texture* texture = nullptr;
};

