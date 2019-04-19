#pragma once
#include <string>
#include <SDL.h>
#include "Font.h"
#include "Color.h"
#include "Rectangle.h"
class Text
{
public:
	Text(const std::string& text, const Color& color, const Position<>& position, SDL_Renderer* renderer, const Font& font);
	void render(SDL_Renderer* renderer) const;
	~Text();
private:
	Text(const Text&) {}
	Color color;
	Rectangle rect;
	SDL_Texture* texture = nullptr;
};

