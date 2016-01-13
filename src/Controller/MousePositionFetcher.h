//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_MOUSEPOSITIONINTERPRETER_H
#define PWASTEROIDS_MOUSEPOSITIONINTERPRETER_H


#include <allegro5/mouse.h>
#include <Model/PrimitiveTypes/Point.h>
#include "AbstractAllegroEventListener.h"

class MousePositionFetcher : public AbstractAllegroEventListener {
    ALLEGRO_MOUSE_STATE msestate;
public:
    virtual void timeEvent();

    Point getMousePosition();
};


#endif //PWASTEROIDS_MOUSEPOSITIONINTERPRETER_H
