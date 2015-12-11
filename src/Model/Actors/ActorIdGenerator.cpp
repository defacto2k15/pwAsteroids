//
// Created by defacto on 05.12.15.
//

#include "ActorIdGenerator.h"

ActorId ActorIdGenerator::getActorId() {
	return ++lastActorId_;
}