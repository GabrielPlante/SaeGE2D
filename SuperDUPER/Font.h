#pragma once
#include <SDL_ttf.h>
#include <string>
class Font
{
public:
	Font(short fontSize, const std::string& fontFileName = "mainFont.ttf");
	TTF_Font* getFont() const { return font; }
	~Font();
private:
	Font(const Font&){}
	TTF_Font* font;
};

