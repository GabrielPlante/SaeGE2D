#pragma once
#include <SDL.h>
#include "Color.h"
//Used to start and stop the sdl text input
struct TextInput
{
public:
	TextInput() { SDL_StartTextInput(); }
	~TextInput() { SDL_StopTextInput(); }
};

