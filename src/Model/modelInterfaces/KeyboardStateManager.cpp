//
// Created by defacto on 09.11.15.
//

#include "KeyboardStateManager.h"


bool  KeyboardStateManager::wasClicked(Keys key) {
	return (pressedKeysMap_.find(key) != pressedKeysMap_.end()) &&( pressedKeysMap_[key] == true)
	       && (previousPressedKeysMap_.find(key) != previousPressedKeysMap_.end())
	       &&(previousPressedKeysMap_[key] == false );
}

bool  KeyboardStateManager::isPressed(Keys key) {
	if( pressedKeysMap_.find(key) == pressedKeysMap_.end()){
		return false;
	} else {
		return (*pressedKeysMap_.find(key)).second;
	}
}

void  KeyboardStateManager::gameKeyIsPressed(Keys key) { // called from keyboard State provider
	pressedKeysMap_[key] = true;
}

void  KeyboardStateManager::OnUpdate() {
	previousPressedKeysMap_ = pressedKeysMap_;
	pressedKeysMap_.clear();
}