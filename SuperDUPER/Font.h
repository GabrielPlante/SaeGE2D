#pragma once
#include <SDL_ttf.h>
#include <string>
class Font
{
public:
	Font(const std::string& fontFileName);
	TTF_Font* getFont() const { return font; }
	~Font();
private:
	TTF_Font* font;
};

