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
	else if (event.type == SDL_MOUSEBUTTONDOWN)
		return EventType::PLAYER;
}

void Event::playerEvent(Player* player) {
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		player->setDestination(x, y);
	}
}

Event::~Event()
{
}
