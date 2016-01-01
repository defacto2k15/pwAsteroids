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

class InputStateManager : public IInputStateProvider, public IInputStateGetter {
	std::map<Keys, bool> previousPressedKeysMap_;
	std::map<Keys, bool> pressedKeysMap_;
	Point mousePosition_ = Point(0,0);

public:
	virtual bool wasClicked(Keys key);

	virtual bool isPressed(Keys key);

	virtual void gameKeyIsPressed(Keys key);

	virtual void OnUpdate();


	virtual void setMousePosition(double x, double y) override;

	virtual Point getMousePosition() override;
};


#endif //PWASTEROIDS_KEYBOARDSTATEMANAGER_H
