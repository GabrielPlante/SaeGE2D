#include "Event.h"
#include "Quit.h"
#include "Attack.h"
#include "Move.h"
#include "GameLoop.h"

Event::Event()
{
	eventToEventType[SDL_QUIT] = std::unique_ptr<Command>{ new Quit() };
	keyToEventType[SDLK_ESCAPE] = std::unique_ptr<Command>{ new Quit() };
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_LEFT)] = std::unique_ptr<Command>{ new Attack() };
	keyToEventType[static_cast<Uint8>(SDL_BUTTON_RIGHT)] = std::unique_ptr<Command>{ new Move() };
}

void Event::handleEvent(GameLoop* gameLoop) {
	if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
		keyboardEvent(gameLoop);
	else if (event.type == SDL_MOUSEMOTION)
		mouseMoveEvent(gameLoop);
	else {
		auto search = eventToEventType.find(event.type);
		if (search != eventToEventType.end())
			search->second->execute(gameLoop, std::vector<float>{});
	}
}

void Event::keyboardEvent(GameLoop* gameLoop) {
	auto search = event.type == SDL_KEYDOWN ? keyToEventType.find(event.key.keysym.sym) : keyToEventType.find(event.button.button);
	//If nothing is found we exit early
	if (search == keyToEventType.end())
		return;
	//Those function need special arguments
	else if (search->second->getName() == "pl_attack") {
		search->second->execute(gameLoop, std::vector<float>{static_cast<float>(event.motion.x), static_cast<float>(event.motion.y)});
	}
	else if (search->second->getName() == "pl_move") {
		search->second->execute(gameLoop, std::vector<float>{static_cast<float>(event.motion.x), static_cast<float>(event.motion.y)});
	}
	//Generic function that can be treated with only gameloop
	else
		search->second->execute(gameLoop, std::vector<float>{});
}

void Event::mouseEvent(LifeForm* player, const Camera& camera, const std::list<std::unique_ptr<LifeForm>>& lifeFormsList) const {
	if (event.type == SDL_MOUSEBUTTONDOWN/* && event.button.button == SDL_BUTTON_RIGHT*/) {
		//First get the mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);//Get the position of the mouse
		//Convert it in absolute position
		Position<> absolutePosition{ camera.relativeToAbsolute(x, y) };//Convert x & y to absolute position
		//If it's a left click, attack (temporary hard coded solution)
		if (event.button.button == SDL_BUTTON_LEFT)
			player->attack(absolutePosition);
		//Then deal with right click, to see if the player clicked on an entity
		bool clickedOnEntity = false;
		for (auto it = lifeFormsList.begin(); it != lifeFormsList.end(); it++) {
			if ((**it).pointIsOnThis(absolutePosition) && player->isInSight((**it).getPosition())) {
				if (event.button.button == SDL_BUTTON_RIGHT) {
					player->setDestination(&(**it));
				}
				clickedOnEntity = true;
				break;
			}
		}
		if (!clickedOnEntity && event.button.button == SDL_BUTTON_RIGHT) {
			player->setDestination(Position<>(absolutePosition.x, absolutePosition.y));
		}
	}
}

void Event::mouseMoveEvent(GameLoop* gameLoop) {
	//If at the last mouse movement the mouse was on a button
	if (buttonHovering) {
		//Check if the mouse is still on the button
		if (!buttonHovering->checkIfHovering(Position<>{static_cast<long>(event.motion.x), static_cast<long>(event.motion.y)}))
			buttonHovering = nullptr;
	}
	//Else we check every button again
	else {
		for (auto it = gameLoop->getButtonList()->begin(); it != gameLoop->getButtonList()->end(); it++) {
			if ((**it).checkIfHovering(Position<>{static_cast<long>(event.motion.x), static_cast<long>(event.motion.y)})) {
				buttonHovering = &(**it);
				break;
			}
		}
	}
}

Event::~Event()
{
}
