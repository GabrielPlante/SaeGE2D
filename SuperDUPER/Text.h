#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Color.h"
#include "Rectangle.h"
class Text
{
public:
	Text(std::string text, Color color, Rectangle position, SDL_Renderer* renderer, TTF_Font* font);
	void render(SDL_Renderer* renderer);
	~Text();
private:
	std::string text;
	Color color;
	Rectangle position;
	SDL_Texture* texture = nullptr;
};

