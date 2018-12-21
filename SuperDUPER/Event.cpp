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
		return EventType::MOUSE;
	return EventType::NONE;
}

void Event::playerEvent(Character* player) {
}

void Event::mouseEvent(Character* player, const Camera& camera) {
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		IntPosition absolutePosition{ camera.relativeToAbsolute(x, y) };
		player->setDestination(IntPosition(absolutePosition.x, absolutePosition.y));
	}
}

Event::~Event()
{
}
