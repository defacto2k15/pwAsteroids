//
// Created by defacto on 2015.12.21..
//

#ifndef PWASTEROIDS_ACTORTYPES_H
#define PWASTEROIDS_ACTORTYPES_H

#include <boost/python/module.hpp>
#include <boost/python/enum.hpp>
#include <boost/python/def.hpp>

enum ActorType{
    ActorType_Invalid = 0,
    ActorType_Rocket = 1,
    ActorType_RocketTail = 2,
    ActorType_Asteroid = 3,
    ActorType_Projectile = 4,
    ActorType_Other = 5,
    ActorType_TripleShootPowerup = 6,
    ActorType_HealthPowerup = 7,
    ActorType_ExplosionCloud = 8
};

std::string getActorTypeString(ActorType type);

#endif //PWASTEROIDS_ACTORTYPES_H
