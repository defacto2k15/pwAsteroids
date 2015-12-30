//
// Created by defacto on 24.10.15.
//

#include "ActorsContainer.h"

void ActorsContainer::addActor(std::shared_ptr<IActor> newActor) {
	assert(!weHaveStarted);
	actorsVec_.push_back(newActor);
}

void ActorsContainer::addActorDuringRuntime(std::shared_ptr<IActor> newActor) {
	newActor->OnStart();
	actorsVec_.push_back(newActor);
}

void ActorsContainer::removeActor(std::shared_ptr<IActor> newActor) {
	auto foundIt = std::find(begin(actorsVec_), end(actorsVec_), newActor);
	if(foundIt == actorsVec_.end()){
		throw RemovingNotAddedActorException();
	}
	(*foundIt)->OnStop();
	actorsVec_.erase(foundIt);
}

std::vector<std::shared_ptr<IService>> ActorsContainer::getServices() {
	std::vector<std::shared_ptr<IService>> outVec(actorsVec_.size());
	std::copy(begin(actorsVec_), end(actorsVec_), begin(outVec));
	return outVec;
}
