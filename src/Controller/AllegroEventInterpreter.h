//
// Created by defacto on 2016.01.11..
//

#ifndef PWASTEROIDS_ALLEGROEVENTINTERPRETER_H
#define PWASTEROIDS_ALLEGROEVENTINTERPRETER_H


#include <allegro5/events.h>
#include <vector>
#include <Model/help/StdContainers.h>
#include <assert.h>
#include "AbstractAllegroEventListener.h"
#include "ScreenEventInterpreter.h"

class AllegroEventInterpreter {
    std::vector<AbstractAllegroEventListener *>listeners_;

public:
    void interpretEvent(ALLEGRO_EVENT event );

    void addListener(AbstractAllegroEventListener *listener);

    void removeListener(ScreenEventInterpreter *interpreter);

private:
    void interpretEvent(AbstractAllegroEventListener *listener, ALLEGRO_EVENT event );
};



#endif //PWASTEROIDS_ALLEGROEVENTINTERPRETER_H
