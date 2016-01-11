//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_ALLEGROEVENTINTERPRETER_H
#define PWASTEROIDS_ALLEGROEVENTINTERPRETER_H


#include <allegro5/events.h>
#include <vector>
#include "AbstractAllegroEventListener.h"

class AllegroEventInterpreter {
    std::vector<AbstractAllegroEventListener *>listeners_;

public:
    void interpretEvent( ALLEGRO_EVENT event ){
        for( auto &oneListener : listeners_){
            interpretEvent(oneListener, event);
        }
    }

    void addListener( AbstractAllegroEventListener *listener){
        listeners_.push_back(listener);
    }
private:
    void interpretEvent(AbstractAllegroEventListener *listener, ALLEGRO_EVENT event ){
        if( event.type == ALLEGRO_EVENT_TIMER){
            listener->timeEvent();
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN ) {
            listener->keyDown(event.keyboard.keycode);
        } else if (event.type == ALLEGRO_EVENT_KEY_UP){
            listener->keyUp(event.keyboard.keycode);
        } else if( event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            listener->mouseKeyDown(event.mouse.button);
        } else if ( event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            listener->mouseKeyUp(event.mouse.button);
        }
    }
};



#endif //PWASTEROIDS_ALLEGROEVENTINTERPRETER_H
