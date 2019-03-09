#pragma once
#include "Key.h"
#include <unordered_set>
#include "LifeForm.h"

//Temporary implementation : every action is an attribute, and a switch is used to identify a key
class KeyActionMap
{
public:
	KeyActionMap();
	void executeAction(Key key, LifeForm* player) const;
	~KeyActionMap();
private:
	Key stop{ SDLK_SPACE };
};

