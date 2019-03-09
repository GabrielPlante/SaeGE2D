#pragma once
#include "GraphicRect.h"
class TextOnRect :
	public GraphicRect
{
public:
	TextOnRect(short w, short h, Color color);
	~TextOnRect();
};

