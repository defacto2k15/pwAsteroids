//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_KEYBOARDSTATEMANAGER_H
#define PWASTEROIDS_KEYBOARDSTATEMANAGER_H


#include "IKeyboardStateProvider.h"
#include "IInKeyboardStateGetter.h"
#include <map>
#include <iostream>

class KeyboardStateManager : public IKeyboardStateProvider, public IInKeyboardStateGetter {
	std::map<Keys, bool> previousPressedKeysMap_;
	std::map<Keys, bool> pressedKeysMap_;


public:
	virtual bool wasClicked(Keys key);

	virtual bool isPressed(Keys key);

	virtual void gameKeyIsPressed(Keys key);

	virtual void OnUpdate();
};


#endif //PWASTEROIDS_KEYBOARDSTATEMANAGER_H
