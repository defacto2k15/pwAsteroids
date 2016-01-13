//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_ALLEGROINPUTINTERPRETER_H
#define PWASTEROIDS_ALLEGROINPUTINTERPRETER_H

#include "AbstractAllegroEventListener.h"
#include <map>
#include <iostream>
#include <vector>

class KeyStateFetcher : public AbstractAllegroEventListener {
    std::map<int, bool> keyStateMap_;
    std::map<int, bool> mouseKeyStateMap_;
public:

    virtual void keyDown(int keynum);

    virtual void keyUp(int keynum);

    virtual void mouseKeyDown(int keynum);

    virtual void mouseKeyUp(int keynum);

    bool isKeyPressed(int keynum);

    bool isMouseKeyPressed(int keynum );

private:
    bool isKeyPressedAccordingToMap(std::map<int, bool> &keysMap, int keynum );
};


#endif //PWASTEROIDS_ALLEGROINPUTINTERPRETER_H
