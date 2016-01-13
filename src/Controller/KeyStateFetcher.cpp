//
// Created by defacto on 2016.01.11..
//

#include "KeyStateFetcher.h"

void KeyStateFetcher::keyDown(int keynum) {
    keyStateMap_[keynum] = true;
}

void KeyStateFetcher::keyUp(int keynum) {
    keyStateMap_[keynum] = false;
}

void KeyStateFetcher::mouseKeyDown(int keynum) {
    mouseKeyStateMap_[keynum] = true;
}

void KeyStateFetcher::mouseKeyUp(int keynum) {
    mouseKeyStateMap_[keynum] = false;
}

bool KeyStateFetcher::isKeyPressed(int keynum) {
    return isKeyPressedAccordingToMap(keyStateMap_, keynum);
}

bool KeyStateFetcher::isMouseKeyPressed(int keynum ) {
    return isKeyPressedAccordingToMap(mouseKeyStateMap_, keynum);
}

bool KeyStateFetcher::isKeyPressedAccordingToMap(std::map<int, bool> &keysMap, int keynum ) {
    if( keysMap.find(keynum) == keysMap.end()){
        keysMap[keynum] = false;
    }
    return keysMap[keynum];
}