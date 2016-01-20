//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_KEYBOARDSTATEMANAGER_H
#define PWASTEROIDS_KEYBOARDSTATEMANAGER_H


#include <Model/modelInterfaces/IInputStateProvider.h>
#include <Model/modelInterfaces/IInputStateGetter.h>
#include <map>
#include <iostream>
#include <Model/PrimitiveTypes/Point.h>
#include <algorithm>

class InputStateManager : public IInputStateProvider, public IInputStateGetter {
	std::map<Keys, bool> previousPressedKeysMap_;
	std::map<Keys, bool> pressedKeysMap_;
	Point mousePosition_ = Point(0,0);
	bool isInterpretingGameInput_ = true;
	std::vector<Keys> exceptionalKeys_;

public:
	virtual bool wasClicked(Keys key);

	virtual bool isPressed(Keys key);

	virtual void gameKeyIsPressed(Keys key);

	virtual void OnUpdate();


	virtual void setMousePosition(double x, double y) override;

	virtual Point getMousePosition() override;

	void turnOffAllKeysInterpretationBut(std::vector<Keys> exceptionalKeys ){
        exceptionalKeys_ = exceptionalKeys;
	}

	void turnOnAllKeysInterpretation(){
	    exceptionalKeys_.clear();
	}

	void turnOffGameKeysInterpretation(){
		isInterpretingGameInput_ = false;
	}

	void turnOnGameKeysInterpretation(){
		isInterpretingGameInput_ = true;
	}

private:
    bool keyIsExceptional( Keys key){
        return std::find( begin(exceptionalKeys_), end(exceptionalKeys_), key) != exceptionalKeys_.end();
    }
};


#endif //PWASTEROIDS_KEYBOARDSTATEMANAGER_H
