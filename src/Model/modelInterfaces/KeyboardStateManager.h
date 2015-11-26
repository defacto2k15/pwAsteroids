//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_KEYBOARDSTATEMANAGER_H
#define PWASTEROIDS_KEYBOARDSTATEMANAGER_H


#include "IKeyboardStateProvider.h"
#include "IInKeyboardStateGetter.h"
#include <map>

class KeyboardStateManager : public IKeyboardStateProvider, public IInKeyboardStateGetter {
	std::map<Keys, bool> previousPressedKeysMap_;
	std::map<Keys, bool> pressedKeysMap_;


public:
	virtual bool wasClicked(Keys key){
		return (pressedKeysMap_.find(key) != pressedKeysMap_.end()) &&( pressedKeysMap_[key] == true)
			&& (previousPressedKeysMap_.find(key) != previousPressedKeysMap_.end())
	            &&(previousPressedKeysMap_[key] == false );
	}

	virtual bool isPressed(Keys key){
		if( pressedKeysMap_.find(key) == pressedKeysMap_.end()){
			return false;
		} else {
			return (*pressedKeysMap_.find(key)).second;
		}
	}

	virtual void gameKeyIsPressed(Keys key){ // called from keyboard State provider
		pressedKeysMap_[key] = true;
	}

	virtual void OnUpdate() override{
		previousPressedKeysMap_ = pressedKeysMap_;
		pressedKeysMap_.clear();
		IInKeyboardStateGetter::notifyObservers();
	}
};


#endif //PWASTEROIDS_KEYBOARDSTATEMANAGER_H
