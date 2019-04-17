#include "TextInput.h"



TextInput::TextInput()
{
	SDL_StartTextInput();
}


TextInput::~TextInput()
{
	SDL_StopTextInput();
}
