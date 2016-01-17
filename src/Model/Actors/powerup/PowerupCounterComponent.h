//
// Created by defacto on 2016.01.16..
//

#ifndef PWASTEROIDS_POWERUPCOUNTERCOMPONENT_H
#define PWASTEROIDS_POWERUPCOUNTERCOMPONENT_H


#include <Model/Actors/IActor.h>
#include "PowerupCounter.h"
#include <Model/components/Component.h>

class PowerupCounterComponent : public Component {
    PowerupCounter &counter_;
public:
    PowerupCounterComponent(PowerupCounter &counter_) : counter_(counter_) { }

    void OnStart(IActor &actor) override {
        counter_.increase();
    }

    void OnStop() override {
        counter_.decrease();
    }

};


#endif //PWASTEROIDS_POWERUPCOUNTERCOMPONENT_H
