//
// Created by defacto on 05.12.15.
//

#ifndef PWASTEROIDS_ACTORIDGENERATOR_H
#define PWASTEROIDS_ACTORIDGENERATOR_H


#include <Model/PrimitiveTypes/AliasedTypes.h>

class ActorIdGenerator {
	ActorId lastActorId_=0;
public:
	ActorId getActorId();
};


#endif //PWASTEROIDS_ACTORIDGENERATOR_H
