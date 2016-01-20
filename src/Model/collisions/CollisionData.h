//
// Created by defacto on 2016.01.17..
//

#ifndef PWASTEROIDS_COLLISIONDATA_H
#define PWASTEROIDS_COLLISIONDATA_H


#include <lib/Box2D/Dynamics/b2Fixture.h>
#include <Model/PrimitiveTypes/Point.h>
#include "CollisionGroups.h"

struct CollisionData {
public:
    CollisionData(const CollisionGroup &collisionGroup, double impulseValue, float otherContactMass,
                  const b2Vec2 &otherContactPosition) : collisionGroup(collisionGroup), impulseValue(impulseValue),
                                                       otherContactMass(otherContactMass),
                                                       otherContactPosition(otherContactPosition) {

    }

    CollisionGroup collisionGroup;
    double impulseValue;
    float otherContactMass;
    b2Vec2 otherContactPosition;
};


#endif //PWASTEROIDS_COLLISIONDATA_H
