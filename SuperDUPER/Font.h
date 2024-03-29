#pragma once
#include <SDL_ttf.h>
#include <string>
class Font
{
public:
	Font(int fontSize, const std::string& fontFileName = "mainFont.ttf");
	TTF_Font* getFont() const { return font; }
	int getWidth(const std::string& text) const;
	int getHeight() const;
	~Font();
private:
	Font(const Font&){}
	TTF_Font* font;
};

