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
    ActorType_RocketTail = 2
};

std::string getActorTypeString(ActorType type);

#endif //PWASTEROIDS_ACTORTYPES_H
