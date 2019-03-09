#include "KeyActionMap.h"



KeyActionMap::KeyActionMap()
{
}

void KeyActionMap::executeAction(Key key, LifeForm* player) const {
	if (key == stop)
		player->clearAction();
}

KeyActionMap::~KeyActionMap()
{
}
