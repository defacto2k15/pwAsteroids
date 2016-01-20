//
// Created by defacto on 2015.12.22..
//
#include "ActorType.h"
#include <iostream>

using namespace boost::python;

std::string getActorTypeString(ActorType type){
        switch( type ){
                case ActorType_Rocket:
                        return "Rocket";
                case ActorType_RocketTail:
                        return "RocketTail";
                case ActorType_Invalid:
                        return "Invalid";
                case ActorType_Asteroid:
                        return "Asteroid";
                case ActorType_Projectile:
                        return "Projectile";
                case ActorType_TripleShootPowerup:
                        return "TripleShootPowerup";
                case ActorType_HealthPowerup:
                        return "HealthPowerup";
                case ActorType_ExplosionCloud:
                        return "ExplosionCloud";
                case ActorType_Other:
                        return "Other";
                default:
                        std::cerr<<" Given actorType that i cant convert to string! ";
                        return "Error";
        }
}
