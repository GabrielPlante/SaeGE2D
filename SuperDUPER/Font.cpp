#include "Font.h"



Font::Font(short fontSize, const std::string& fontFileName)
{
	font = TTF_OpenFont(fontFileName.c_str(), fontSize);
	if (!font)
		throw std::runtime_error("Could not open the font !");
}

Font::~Font()
{
	TTF_CloseFont(font);
}
