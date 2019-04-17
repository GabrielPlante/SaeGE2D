#pragma once
#include <string>
#include <SDL.h>
#include "Font.h"
#include "Color.h"
#include "Rectangle.h"
class Text
{
public:
	Text(const std::string& text, Color color, Rectangle position, SDL_Renderer* renderer, const std::string& fontFileName = "mainFont.ttf");
	void render(SDL_Renderer* renderer) const;
	~Text();
private:
	Text(const Text&) {}
	Color color;
	Rectangle position;
	SDL_Texture* texture = nullptr;
};

