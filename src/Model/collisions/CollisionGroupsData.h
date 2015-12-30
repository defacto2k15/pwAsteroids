//
// Created by defacto on 2015.12.28..
//

#ifndef PWASTEROIDS_COLLISIONGROUPSDATA_H
#define PWASTEROIDS_COLLISIONGROUPSDATA_H


#include "CollisionGroups.h"

class CollisionGroupsData {
public:
    unsigned short categoryBits_;
    unsigned short maskBits_;
    CollisionGroupsData(unsigned int categoryBits, unsigned int maskBits) : categoryBits_(categoryBits),
                                                                              maskBits_(maskBits) {
    }

    static CollisionGroupsData getAsteroidData();;

    static CollisionGroupsData getRocketData();

    static CollisionGroupsData getProjectileData();
};


#endif //PWASTEROIDS_COLLISIONGROUPSDATA_H
