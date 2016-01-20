//
// Created by defacto on 2016.01.11..
//

#include "AllegroEventInterpreter.h"

void AllegroEventInterpreter::interpretEvent(ALLEGRO_EVENT event ) {
	
    /*for( auto &oneListener : listeners_)
	{
        interpretEvent(oneListener, event);
    }*/
	for (int i = 0; i < listeners_.size(); ++i) {
		interpretEvent(listeners_[i], event);
	}
}

void AllegroEventInterpreter::addListener(AbstractAllegroEventListener *listener) {
    listeners_.push_back(listener);
}

void AllegroEventInterpreter::removeListener(ScreenEventInterpreter *interpreter) {
    if( std::find(std::begin(listeners_), listeners_.end(), interpreter) == listeners_.end()){
        assert(false);
    }
    listeners_.erase(std::remove(listeners_.begin(), listeners_.end(), interpreter), listeners_.end());
}

void AllegroEventInterpreter::interpretEvent(AbstractAllegroEventListener *listener, ALLEGRO_EVENT event ) {
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
    } else if (event.type == ALLEGRO_EVENT_KEY_CHAR ){
        listener->charKeyDown( event.keyboard.unichar );
    }
}