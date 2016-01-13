//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_ALLEGROINPUTINTERPRETER_H
#define PWASTEROIDS_ALLEGROINPUTINTERPRETER_H

#include "AbstractAllegroEventListener.h"
#include <map>
#include <iostream>

class KeyStateFetcher : public AbstractAllegroEventListener {
    std::map<int, bool> keyStateMap_;
    std::map<int, bool> mouseKeyStateMap_;
public:

    virtual void keyDown(int keynum) override{
        keyStateMap_[keynum] = true;
    }

    virtual void keyUp(int keynum) override{
        keyStateMap_[keynum] = false;
    }

    virtual void mouseKeyDown(int keynum) override{
        mouseKeyStateMap_[keynum] = true;
    }

    virtual void mouseKeyUp(int keynum) override{
        mouseKeyStateMap_[keynum] = false;
    }

    bool isKeyPressed(int keynum){
        return isKeyPressedAccordingToMap(keyStateMap_, keynum);
    }

    bool isMouseKeyPressed(int keynum ){
        return isKeyPressedAccordingToMap(mouseKeyStateMap_, keynum);
    }

private:
    bool isKeyPressedAccordingToMap(std::map<int, bool> &keysMap, int keynum ){
        if( keysMap.find(keynum) == keysMap.end()){
            keysMap[keynum] = false;
        }
        return keysMap[keynum];
    }
};


#endif //PWASTEROIDS_ALLEGROINPUTINTERPRETER_H
