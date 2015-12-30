//
// Created by defacto on 2015.12.29..
//

#ifndef PWASTEROIDS_CONTACTCOMPONENTSCONTAINER_H
#define PWASTEROIDS_CONTACTCOMPONENTSCONTAINER_H

#include <memory>
#include <lib/Box2D/Dynamics/b2Body.h>
#include <map>
#include <stdexcept>
#include "Box2dCollisionsComponent.h"

class ContactComponentsContainer {
    std::map< b2Body *, Box2dCollisionsComponent*> bodiesToComponentsMap_;
public:

    Box2dCollisionsComponent *getComponentForBody(b2Body *body );

    void registerCollisionComponent(b2Body *body, Box2dCollisionsComponent *component);

    void deregisterCollisionComponent(b2Body *body);

private:
    void assertThereIsRegisteredBody(b2Body *body);
};


#endif //PWASTEROIDS_CONTACTCOMPONENTSCONTAINER_H
