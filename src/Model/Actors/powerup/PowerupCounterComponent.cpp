//
// Created by defacto on 2016.01.16..
//

#include "PowerupCounterComponent.h"

PowerupCounterComponent::PowerupCounterComponent(PowerupCounter &counter_) : counter_(counter_) { }

void PowerupCounterComponent::OnStart(IActor &actor) {
    counter_.increase();
}

void PowerupCounterComponent::OnStop() {
    counter_.decrease();
}