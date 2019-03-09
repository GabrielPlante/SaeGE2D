#include "Font.h"



Font::Font(const std::string& fontFileName)
{
	font = TTF_OpenFont(fontFileName.c_str(), fontFileName.size());
}

Font::~Font()
{
	TTF_CloseFont(font);
}
