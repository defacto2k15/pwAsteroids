//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_IKEYBOARDSTATEPROVIDER_H
#define PWASTEROIDS_IKEYBOARDSTATEPROVIDER_H
#include "Keys.h"
#include <Model/PrimitiveTypes/Point.h>

class IInputStateProvider {
public:
	virtual bool wasClicked(Keys key)=0;
	virtual bool isPressed(Keys key)=0;
	virtual Point getMousePosition()=0;
	virtual ~IInputStateProvider(){};

};
#endif //PWASTEROIDS_IKEYBOARDSTATEPROVIDER_H
