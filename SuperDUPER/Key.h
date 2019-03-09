#pragma once
#include <SDL.h>
#include <functional>
class LifeForm;
struct Key
{
	Key(SDL_Keycode key) : key{ key } {}
	SDL_Keycode getKey() const { return key; }
	void changeKey(SDL_Keycode newKey) { key = newKey; }
	bool operator==(const Key& other) const { return key == other.getKey(); }
private:
	SDL_Keycode key;
};