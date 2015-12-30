//
// Created by defacto on 2015.12.28..
//

#include "CollisionGroupsData.h"

CollisionGroupsData CollisionGroupsData::getAsteroidData() {
    return CollisionGroupsData( CollisionGroup::CollisionGroup_Asteroid,
                                CollisionGroup::CollisionGroup_Asteroid | CollisionGroup::CollisionGroup_Projectile | CollisionGroup::CollisionGroup_Rocket);
}

CollisionGroupsData CollisionGroupsData::getRocketData() {
    return CollisionGroupsData( CollisionGroup::CollisionGroup_Rocket,
                                CollisionGroup::CollisionGroup_Asteroid);
}

CollisionGroupsData CollisionGroupsData::getProjectileData() {
    return CollisionGroupsData( CollisionGroup::CollisionGroup_Projectile,
                                  CollisionGroup::CollisionGroup_Asteroid);
}