#pragma once
#include <SDL.h>
struct Key
{
	Key(SDL_Keycode key) : key{ key }, isKey{ true } {}
	Key(Uint8 mouseButton) : mouseButton{ mouseButton }, isKey{ false } {}
	void changeKey(SDL_Keycode newKey) { key = newKey; isKey = true; }
	void changeKey(Uint8 newMouseButton) { mouseButton = newMouseButton; isKey = false; }
	//Those method shall not be used, they are only useful for the operator==
	SDL_Keycode getKey() const { return key; }
	Uint8 getMouseButton() const { return mouseButton; }
	bool getIsKey() const { return isKey; }
	bool operator==(const Key& other) const {
		if (isKey != other.getIsKey())
			return false;
		return isKey ? key == other.getKey() : mouseButton == other.getMouseButton();
	}
private:
	SDL_Keycode key;
	Uint8 mouseButton;
	//The "key" is either a key or a mouse button, this bool is how we know which is it
	bool isKey;
};

inline bool operator<(const Key& left, const Key& right) {
	//A mouseButton is superior to a key (had to choose)
	if (left.getIsKey() != right.getIsKey())
		return left.getIsKey();
	return left.getIsKey() ? left.getKey() < right.getKey() : left.getMouseButton() < right.getMouseButton();
}