//
// Created by defacto on 2016.01.11..
//

#include "MousePositionFetcher.h"

void MousePositionFetcher::timeEvent() {
    al_get_mouse_state(&msestate);
}

Point MousePositionFetcher::getMousePosition() {
    return Point (al_get_mouse_state_axis(&msestate, 0),
                  al_get_mouse_state_axis(&msestate, 1) );
}