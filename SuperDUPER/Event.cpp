#include "Event.h"



Event::Event()
{
}

bool Event::pollEvent() {
	return SDL_PollEvent(&event);
}

EventType Event::getEventType() {
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
		return EventType::QUIT;
}

Event::~Event()
{
}
