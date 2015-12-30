//
// Created by defacto on 2015.12.29..
//

#include "ContactComponentsContainer.h"

Box2dCollisionsComponent * ContactComponentsContainer::getComponentForBody(b2Body *body ) {
    assertThereIsRegisteredBody(body);
    return bodiesToComponentsMap_[body];
}

void ContactComponentsContainer::registerCollisionComponent(b2Body *body, Box2dCollisionsComponent * component) {
    bodiesToComponentsMap_[body] = component;
}

void ContactComponentsContainer::deregisterCollisionComponent(b2Body *body) {
    assertThereIsRegisteredBody(body);
    bodiesToComponentsMap_.erase(body);
}

void ContactComponentsContainer::assertThereIsRegisteredBody(b2Body *body) {
    if( bodiesToComponentsMap_.count( body ) == 0){
        throw std::runtime_error("There is no registered bo2dCollisionComponent for that body");
    }
}