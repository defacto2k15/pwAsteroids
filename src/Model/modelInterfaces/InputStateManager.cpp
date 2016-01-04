//
// Created by defacto on 09.11.15.
//

#include "InputStateManager.h"
#include <iostream>
#include <Model/PrimitiveTypes/Point.h>
#include <iostream>

bool  InputStateManager::wasClicked(Keys key) {
	bool returnedValue =  (pressedKeysMap_.find(key) != pressedKeysMap_.end()) &&( pressedKeysMap_[key] == true)
	       && ( !(previousPressedKeysMap_.find(key) != previousPressedKeysMap_.end()) ||
	      		 (previousPressedKeysMap_[key] == false ));
	return returnedValue;
}

bool  InputStateManager::isPressed(Keys key) {
	if( pressedKeysMap_.find(key) == pressedKeysMap_.end()){
		return false;
	} else {
		return (*pressedKeysMap_.find(key)).second;
	}
}

void  InputStateManager::gameKeyIsPressed(Keys key) { // called from input State provider
	if( isInterpretingGameInput_ || key == Keys::PauseKey ) {
		pressedKeysMap_[key] = true;
	}
}

void  InputStateManager::OnUpdate() {
	previousPressedKeysMap_ = pressedKeysMap_;
	pressedKeysMap_.clear();
}

void InputStateManager::setMousePosition(double x, double y) {
	if( isInterpretingGameInput_) {
		mousePosition_ = Point(x, y);
	}
}

Point InputStateManager::getMousePosition() {
	return mousePosition_;
}
