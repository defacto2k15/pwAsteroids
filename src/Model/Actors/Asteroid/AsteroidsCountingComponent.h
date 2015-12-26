//
// Created by defacto on 2015.12.26..
//

#ifndef PWASTEROIDS_ASTEROIDSCOUNTINGCOMPONENT_H
#define PWASTEROIDS_ASTEROIDSCOUNTINGCOMPONENT_H


#include <Model/components/Component.h>
#include "AsteroidsCounter.h"

class AsteroidsCountingComponent : public Component {
    std::shared_ptr<AsteroidsCounter> counter_;
public:
    AsteroidsCountingComponent( std::shared_ptr<AsteroidsCounter> counter ) : counter_(counter){
    }

    void OnStart( IActor &actor) override {
        counter_->Increment();
    }

    void OnStop() override {
        counter_->Decrement();
    }

};


#endif //PWASTEROIDS_ASTEROIDSCOUNTINGCOMPONENT_H
