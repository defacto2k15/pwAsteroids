//
// Created by defacto on 2016.01.17..
//

#ifndef PWASTEROIDS_COLLISIONDATA_H
#define PWASTEROIDS_COLLISIONDATA_H


#include <lib/Box2D/Dynamics/b2Fixture.h>
#include "CollisionGroups.h"

struct CollisionData {
    CollisionData(const CollisionGroup collisionGroup, double impulseValue, b2Fixture *otherContacterFixture)
            : collisionGroup(collisionGroup), impulseValue(impulseValue),
              otherContacterFixture(otherContacterFixture) {
    }

    CollisionGroup collisionGroup;
    double impulseValue;
    b2Fixture *otherContacterFixture;
};


#endif //PWASTEROIDS_COLLISIONDATA_H
