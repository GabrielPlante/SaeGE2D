#include "Font.h"



Font::Font(short fontSize, const std::string& fontFileName)
{
	font = TTF_OpenFont(fontFileName.c_str(), fontSize);
}

Font::~Font()
{
	TTF_CloseFont(font);
}
