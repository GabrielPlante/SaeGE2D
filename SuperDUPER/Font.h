#pragma once
#include <SDL_ttf.h>
#include <string>
class Font
{
public:
	Font(short fontSize, const std::string& fontFileName = "mainFont.ttf");
	TTF_Font* getFont() const { return font; }
	short getFontSize() const { return fontSize; }
	int getWidth(const std::string& text) const;
	int getHeight() const;
	~Font();
private:
	Font(const Font&){}
	short fontSize;
	TTF_Font* font;
};

