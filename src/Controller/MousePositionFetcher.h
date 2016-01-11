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
    virtual void timeEvent() override{
        al_get_mouse_state(&msestate);
    }

    Point getMousePosition(){
        return Point (al_get_mouse_state_axis(&msestate, 0),
                      al_get_mouse_state_axis(&msestate, 1) );
    }
};


#endif //PWASTEROIDS_MOUSEPOSITIONINTERPRETER_H
