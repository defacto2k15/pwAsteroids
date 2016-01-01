//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_ASTEROIDSCOUNTINGCOMPONENT_H
#define PWASTEROIDS_ASTEROIDSCOUNTINGCOMPONENT_H


#include <Model/components/Component.h>
#include "AsteroidsCounter.h"

class AsteroidsCountingComponent : public Component {
    AsteroidsCounter &counter_;
public:
    AsteroidsCountingComponent(AsteroidsCounter &counter );

    void OnStart(IActor &actor);

    void OnStop();

};


#endif //PWASTEROIDS_ASTEROIDSCOUNTINGCOMPONENT_H
