//
// Created by defacto on 26.10.15.
//

#ifndef PWASTEROIDS_IKEYBOARDSTATEPROVIDER_H
#define PWASTEROIDS_IKEYBOARDSTATEPROVIDER_H
#include "Keys.h"

class IKeyboardStateProvider {
public:
	virtual bool wasClicked(Keys key)=0;
	virtual bool isPressed(Keys key)=0;
	virtual ~IKeyboardStateProvider(){};

};
#endif //PWASTEROIDS_IKEYBOARDSTATEPROVIDER_H
