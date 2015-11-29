//
// Created by defacto on 09.11.15.
//

#ifndef PWASTEROIDS_INKEYBOARDSTATEGETTER_H
#define PWASTEROIDS_INKEYBOARDSTATEGETTER_H

#include <Model/Services/IService.h>
#include "Model/Observer/Observable.h"
#include "Keys.h"

class IInKeyboardStateGetter :  public IService {
public:
	virtual void gameKeyIsPressed(Keys key)=0;
};


#endif //PWASTEROIDS_INKEYBOARDSTATEGETTER_H
